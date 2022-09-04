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
using namespace std;
typedef long long LL;
struct node{
	node *l,*r;
	int a,b;
	int Min;
	node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b){
		Min=1e9+1;
	}
};
node* Clone(node *n){
	node *a=new node(n->a,n->b);
	a->l=n->l;
	a->r=n->r;
	a->Min=n->Min;
	return a; 
}
int Min(node *n){
	return n?n->Min:1e9+1;
} 
void pull(node *n){
	n->Min=min(Min(n->l),Min(n->r));
}
node * root[200005];
void add(node *n,int x,int a){
	if(n->a==n->b){
		n->Min=min(n->Min,a);
		return;
	}
	int mid=(n->a+n->b)/2;
	if(x<=mid){
		if(!n->l)
		n->l=new node(n->a,mid);
		else
		n->l=Clone(n->l);
		add(n->l,x,a);
	}
	else{
		if(!n->r)
		n->r=new node(mid+1,n->b);
		else
		n->r=Clone(n->r);
		add(n->r,x,a);
	}
	pull(n);
}
int query(node *n,int l,int r){
	if(l>r)
	return 1e9+1;
	if(!n)
	return 1e9+1;
	if(n->a==l&&n->b==r)
	return n->Min;
	int a=query(n->l,l,min((n->a+n->b)/2,r));
	int b=query(n->r,max((n->a+n->b)/2+1,l),r);
	return min(a,b);
}
int in[100005];
int out[100005];
pii dep[100005];
int de[100005];
int t=0;
vector<int> v[100005];
void dfs(int x,int f,int d){
	in[x]=++t;
	de[x]=d;
	dep[x]=mp(d,x);
	for(auto it=v[x].begin();it!=v[x].end();it++){
		if(*it!=f){
			dfs(*it,x,d+1);
		}
	}
	out[x]=t;
}
int main(){
	int n,r;
	scanf("%d %d",&n,&r);
	int a[100005];
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(r,0,0);
	sort(dep+1,dep+n+1);
	root[0]=new node(1,n);
	int last=0;
	for(int i=1;i<=n;i++){
	//	printf("%d %d %d\n",dep[i].x,dep[i].y,a[dep[i].y]);
		if(dep[i].x==last){
			add(root[last],in[dep[i].y],a[dep[i].y]);
		}
		else{
			root[dep[i].x]=Clone(root[last]);
			last=dep[i].x;
			add(root[last],in[dep[i].y],a[dep[i].y]);
		}
	}
	for(int i=last+1;i<2*n;i++){
		root[i]=Clone(root[i-1]);
	}
	int q;
	scanf("%d",&q);
	int lastans=0;
	while(q--){
		int x,k;
		scanf("%d %d",&x,&k);
		x=(x+lastans)%n+1;
		k=(k+lastans)%n;
	//	printf("%d %d\n",x,k);
		printf("%d\n",lastans=query(root[de[x]+k],in[x],out[x]));
	}
}