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
	int tag;
	int Min;
	node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),tag(0){}
}*root;
int Min(node *n){
	return n->Min+n->tag;
}
void pull(node *n){
	n->Min=min(Min(n->l),Min(n->r));
}
void push(node *n){
	n->l->tag+=n->tag;
	n->r->tag+=n->tag;
	n->tag=0;
}
void build(node *n){
	if(n->a==n->b){
		n->Min=0;
		return;
	}
	int mid=(n->a+n->b)/2;
	n->l=new node(n->a,mid);
	n->r=new node(mid+1,n->b);
	build(n->l);
	build(n->r);
}
void add(node *n,int l,int r,int k){
	if(l>r)return;
	if(n->a>=l&&n->b<=r){
		n->tag+=k;return;
	}
	if(n->b<l||n->a>r)return;
	push(n);
	add(n->l,l,r,k);
	add(n->r,l,r,k);
	pull(n);
}
int query(node *n,int l,int r){
	if(l>r)return 0;
	if(n->a>=l&&n->b<=r)return Min(n);
	if(n->b<l||n->a>r)return 1e9;
	push(n);
	int res=min(query(n->l,l,r),query(n->r,l,r));
	pull(n);
	return res;
}
int last[100005];
void solve(){
	int n;
	scanf("%d",&n);
	int a[100005];
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
	}
	vector<int> v;
	v.pb(0);
	for(int i = 0;i<n;i++){
		if(v.empty()||v.back()!=a[i])v.pb(a[i]);
		last[a[i]]=0;
	//	Min[a[i]]=1e9;
	}
	root = new node(0,v.size()-1);
	build(root);
	for(int i = 1;i<v.size();i++){
		int res=query(root,0,i-2)+1;
		if(last[v[i]]!=0)
		res=min(res,query(root,last[v[i]],last[v[i]]));
		last[v[i]]=i;
		add(root,0,i-2,1);
		add(root,i-1,i-1,res);
	}
	if(v.size()-1<=2){
		printf("%d\n",v.size()-1);
	}
	else
	printf("%d\n",query(root,v.size()-2,v.size()-2));
}
int main(){
    int t=1;00000;//00000;
    //scanf("%d",&t);
    while(t--)solve();
}
/*

*/