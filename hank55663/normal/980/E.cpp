#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
using namespace std;
vector<int> v[1000005];
int ok[1000005];
int f[1000005];
int in[1000005];
int out[1000005];
int rev[1000005];
int t;
struct node{
	node *l,*r;
	int a,b;
	int tag;
	node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b){
		tag=0;
	}
}*root;
int dep[1000005];
void push(node *n){
	n->l->tag+=n->tag;
	n->r->tag+=n->tag;
	n->tag=0;
}
void build(node *n){
	if(n->a==n->b){
		n->tag=dep[rev[n->a]];
		return ;
	}
	int mid=(n->a+n->b)/2;
	n->l=new node(n->a,mid);
	n->r=new node(mid+1,n->b);;
	build(n->l);
	build(n->r);
}
void add(node *n,int l,int r,int k){
	if(n->a>=l&&n->b<=r){
		n->tag+=k;
		return ;
	}
	if(n->b<l||n->a>r){
		return ;
	}
	push(n);
	add(n->l,l,r,k);
	add(n->r,l,r,k);
}
int query(node *n,int x){
	if(n->a==n->b){
		return n->tag;
	}
	push(n);
	int mid=(n->a+n->b)/2;
	if(x<=mid)return query(n->l,x);
	else return query(n->r,x);
}
void dfs(int x,int F){
	in[x]=++t;
	rev[t]=x;
	f[x]=F;
	dep[x]=dep[F]+1;
	for(auto it:v[x]){
		if(it!=F){
			dfs(it,x);
		}
	}
	out[x]=t;
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	fill(ok,ok+n+1,-1);
	for(int i =0;i<n-1;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	ok[n]=1;
	dep[0]=-1;
	dfs(n,0);
	root = new node(1,n);
	build(root);
	int now=n-k-1;
	vector<int> ans;
	for(int i=n;i>=1;i--){
		int x=query(root,in[i]);
		if(x<=now){
			now-=x;
			int temp=i;
			for(int j = 0;j<x;j++){
				add(root,in[temp],out[temp],-1);
				temp=f[temp];
			}
		}
		else{
			ans.pb(i);
		}
	}
	reverse(ans.begin(),ans.end());
	for(auto it:ans)
	printf("%d ",it);
}