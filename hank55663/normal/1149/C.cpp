
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
#define MMax(x,y,z) max(max(x,y),z)
using namespace std;
typedef long long LL;
struct node{
	node *l,*r;
	int a,b;
	int Max;
	int ans;
	int sum;
	int sufneg,sufans;
	int prepos,preans;
	node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b){

	}
}*root;
int value[200005];
void pull(node *n){
	n->sum=n->l->sum+n->r->sum;
	n->Max=max(max(n->l->Max,n->r->Max),max(n->r->preans-n->l->sufneg,n->r->prepos+n->l->sufans));
	n->ans=max(n->l->ans+n->r->sum,n->r->ans-n->l->sum);
	n->sufneg=min(n->r->sufneg,n->l->sufneg+n->r->sum);
	n->prepos=max(n->l->prepos,n->r->prepos+n->l->sum);
	n->sufans=MMax(n->r->sufans,n->l->sufans+n->r->sum,n->r->ans-n->l->sufneg);
	n->preans=MMax(n->l->preans,n->r->preans-n->l->sum,n->l->ans+n->r->prepos);
}
void build(node *n){
	if(n->a==n->b){
		n->sum=value[n->a];
		n->Max=1;
		n->ans=1;
		n->sufneg=min(value[n->a],0);
		n->prepos=max(value[n->a],0);
		n->sufans=1;
		n->preans=1;
		n->Max=value[n->a];
		return ;
	}
	int mid=(n->a+n->b)/2;
	n->l=new node(n->a,mid);
	n->r=new node(mid+1,n->b);
	build(n->l);
	build(n->r);
	pull(n);
}
void revise(node *n,int x,int k){
	if(n->a==n->b){
		n->sum=k;
		n->Max=1;
		n->ans=1;
		n->sufneg=min(k,0);
		n->prepos=max(k,0);
		n->sufans=1;
		n->preans=1;
		return;
	}
	int mid=(n->a+n->b)/2;
	if(x<=mid)
	revise(n->l,x,k);
	else
	revise(n->r,x,k);
	pull(n);
}
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	root=new node(1,2*(n-1));
	char c[200005];
	scanf("%s",c+1);
	value[0]=0;
	for(int i = 1;c[i]!=0;i++){
		if(c[i]=='(')
			value[i]=1;
		else
			value[i]=-1;
	}
	build(root);
	printf("%d\n",root->Max);
	while(q--){
		int l,r;
		scanf("%d %d",&l,&r);
		if(c[l]==c[r]);
		else if(c[l]=='('){
			revise(root,l,-1);
			revise(root,r,1);
			swap(c[l],c[r]);
		}
		else{
			revise(root,l,1);
			revise(root,r,-1);
			swap(c[l],c[r]);
		}
		printf("%s",c);
		printf("%d\n",root->Max);
	}
}