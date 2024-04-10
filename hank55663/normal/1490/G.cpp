#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
struct node{
	node *l,*r;
	int a,b;
	LL Max;
	node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),Max(0){

	}
}*root;
void pull(node *n){
	n->Max=max(n->l->Max,n->r->Max);
}
void build(node *n,LL *a){
	if(n->a==n->b){
		n->Max=a[n->a];
		return;
	}
	int mid=(n->a+n->b)/2;
	n->l=new node(n->a,mid);
	n->r=new node(mid+1,n->b);
	build(n->l,a);
	build(n->r,a);
	pull(n);
}
int query(node *n,LL k){
	assert(n->Max>=k);
	if(n->a==n->b)return n->a;
	if(n->l->Max>=k)return query(n->l,k);
	else return query(n->r,k);
}
bool solve(){
	int n,q;
	scanf("%d %d",&n,&q);
	int a[200005];
	LL pre[200005];
	for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
	//a[1]=2;
	pre[0]=0;
	for(int i = 1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	root=new node(1,n);
	build(root,pre);
	while(q--){
		int x;
		scanf("%d",&x);
		LL d=x-root->Max;
		if(d<=0){
			printf("%d ",query(root,x)-1);
		}
		else{
			if(pre[n]<=0){
				printf("-1 ");
			}
			else{
				LL sum=(d+pre[n]-1)/pre[n];
				x=x-sum*pre[n];
				assert(x>0);
				sum*=n;
				printf("%lld ",query(root,x)+sum-1);
			}
		}
	}
	printf("\n");
	return true;
}
int main(){
	int t=1;//000000;
    scanf("%d",&t);
    while(t--)solve();
}