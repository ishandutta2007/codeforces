#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
#define index Index
#define N 300005
using namespace std;
typedef long long LL;
struct node{
	int a,b;
	node *l,*r;
	int Max;
	LL sum;
	node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL){
		Max=0;
		sum=0;
	} 
}*root;
int a[300005];
int d[1000005];
void pull(node *n){
	n->sum=n->l->sum+n->r->sum;
	n->Max=max(n->l->Max,n->r->Max); 
}
void build(node *n){
	if(n->a==n->b){
		n->Max=n->sum=a[n->a];
		return;
	}
	int mid=(n->a+n->b)/2;
	n->l=new node(n->a,mid);
	n->r=new node(mid+1,n->b);
	build(n->l);
	build(n->r);
	pull(n);
}
void revise(node *n,int l,int r){
	if(n->b<l||n->a>r){
		return ;
	}
	if(n->a==n->b){
		n->Max=d[n->Max];
		n->sum=d[n->sum];
	//	printf("%d %d\n",n->a,n->sum);
		return;
	}
	if(n->a>=l&&n->b<=r){
		if(n->Max<=2){
			return;
		}
	}
	revise(n->l,l,r);
	revise(n->r,l,r);
	pull(n);
}
LL sum(node *n,int l,int r){
	if(n->b<l||n->a>r){
		return 0;
	}
	if(n->a>=l&&n->b<=r){
		return n->sum;
	}
	return sum(n->l,l,r)+sum(n->r,l,r);
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=1000000;i++){
		for(int j=i;j<=1000000;j+=i)
		d[j]++;
	}
//	printf("%d\n",d[4]);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	root=new node(1,n);
	build(root);
	while(m--){
		int op,l,r;
		scanf("%d %d %d",&op,&l,&r);
		if(op==1){
			revise(root,l,r);
		}
		else{
			printf("%lld\n",sum(root,l,r));
		}
	} 
}