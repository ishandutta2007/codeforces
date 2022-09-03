#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
using namespace std;
vector<int> v[1000005];
int ans[1000005];
struct node{
	node *l,*r;
	int a, b;
	LL Max;
	LL tag;
	node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),Max(0),tag(0){
	}
}*root;
LL Max(node *n){
	return n->Max+n->tag;
}
void push(node *n){
	n->l->tag+=n->tag;
	n->r->tag+=n->tag;
	n->tag=0;
}
void pull(node *n){
	n->Max=max(Max(n->l),Max(n->r));
}
void build(node *n){
	if(n->a==n->b)return;
	int mid=(n->a+n->b)/2;
	n->l=new node(n->a,mid);
	n->r=new node(mid+1,n->b);
	build(n->l);
	build(n->r);
}
void add(node *n,int l,int r,int k){
	if(n->a>=l&&n->b<=r){
		n->tag+=k;
		return ;
	}
	if(n->b<l||n->a>r)return;
	push(n);
	add(n->l,l,r,k);
	add(n->r,l,r,k);
	pull(n);
}
int in[1000005];
int out[1000005];
int t;
int a[1000005];
void dfs(int x){
	in[x]=++t;
	for(auto it:v[x]){
		dfs(it);
	}
	out[x]=t;
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i = 1;i<=n;i++)
		scanf("%d",&a[i]);
	a[n+1]=1e9;
	vector<pii> mystk;
	mystk.pb(mp(1e9+1,0));
	for(int i =1;i<=n+1;i++){
		while(mystk.back().x<a[i]){
			v[i].pb(mystk.back().y);
			mystk.pop_back();
		}
		mystk.pb(mp(a[i],i));
	}
	dfs(n+1);
	root = new node(1,n+1);
	build(root);
	for(int i =1;i<=k;i++){
		add(root,in[i],out[i],1);
	}
	for(int i =k+1;i<=n+1;i++){
		printf("%lld ",Max(root));
		add(root,in[i-k],in[i-k],-1e9);
		add(root,in[i],out[i],1);
	}
}
//y-x^2 = bx+c
// A= Bb+Cc
// D= Eb+Fc