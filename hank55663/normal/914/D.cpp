#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
struct node{
	node *l,*r;
	int GCD;
	int a,b;
	node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL){
		GCD=1;
	} 
}*root;
int a[500005];
void pull(node *n){
	n->GCD=__gcd(n->l->GCD,n->r->GCD);
}
void build(node *n){
	if(n->a==n->b){
		n->GCD=a[n->a];
		return ;	
	}
	int mid=(n->a+n->b)/2;
	n->l=new node(n->a,mid);
	n->r=new node(mid+1,n->b);
	build(n->l);
	build(n->r);
	pull(n);
}
void change(node *n,int k,int y){
	if(n->a==n->b){
		n->GCD=y;
		return; 
	}
	int mid=(n->a+n->b)/2;
	if(k>mid)
	change(n->r,k,y);
	else
	change(n->l,k,y);
	pull(n);
} 
int query(node *n,int a,int b,int k){
	if(n->GCD%k==0)
		return 0;
	if(n->a>=a&&n->b<=b){
		if(n->a==n->b)
		return 1;
		else if(n->l->GCD%k!=0&&n->r->GCD%k!=0)
		return 2;
		else if(n->l->GCD%k==0)
		return query(n->r,a,b,k);
		else
		return query(n->l,a,b,k);
	}
	int mid=(n->a+n->b)/2;
	if(a>mid)
	return query(n->r,a,b,k);
	if(b<=mid)
	return query(n->l,a,b,k);
	int x=query(n->l,a,b,k);
	if(x==2)
	return 2;
	else
	return x+query(n->r,a,b,k);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	root = new node(1,n);
	build(root);
	int q;
	scanf("%d",&q);
	while(q--){
		int op;
		scanf("%d",&op);
		if(op==1){
			int l,r,x;
			scanf("%d %d %d",&l,&r,&x);
			int ans=query(root,l,r,x);
			if(ans>=2)
			printf("NO\n");
			else
			printf("YES\n");
		}
		else{
			int i,y;
			scanf("%d %d",&i,&y);
			change(root,i,y);
		}
	}
}