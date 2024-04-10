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
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
vector<int> v[200005];
int t[200005];
int in[200005];
int out[200005];
int ti;
void dfs(int n){
	in[n]=++ti;
	for(auto it=v[n].begin();it!=v[n].end();it++){
		dfs(*it);
	}
	out[n]=ti;
}
struct node{
	node *l,*r;
	int tag;
	int a,b;
	int sum;
	node(int _a,int _b):l(NULL),r(NULL){
		tag=0;
		a=_a;
		b=_b;
		sum=0; 
	}
}*root;
int Sum(node *n){
	if(n->tag)
	return n->b-n->a+1-n->sum;
	return n->sum;
}
void pull(node *n){
	n->sum=Sum(n->l)+Sum(n->r);
}
void push(node *n){
	if(n->tag)
	{
		n->l->tag^=1;
		n->r->tag^=1;
		n->tag=0;
	}
}
void build(node *n,int a,int b){
	if(a==b){
		n->sum=t[a];
		return ;
	}
	int mid=(a+b)/2;
	n->l=new node(a,mid);
	n->r=new node(mid+1,b);
	build(n->l,a,mid);
	build(n->r,mid+1,b);
	pull(n);
}
int query(node *n,int a,int b){
	if(b<a)
	return 0;
	if(n->a==a&&n->b==b){
		return Sum(n);
	}
	push(n);
	int ans=query(n->l,a,min(n->l->b,b))+query(n->r,max(n->r->a,a),b);
	pull(n);
	return ans; 
}
void revise(node *n,int a,int b){
	if(b<a)
	return ;
	if(n->a==a&&n->b==b){
		n->tag^=1;
		return ;
	}
	push(n);
	revise(n->l,a,min(n->l->b,b));
	revise(n->r,max(n->r->a,a),b);
	pull(n);
}
int main(){
	int n;
	ti=0;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		int a;
		scanf("%d",&a);
		v[a].pb(i);
	}
	dfs(1);
	for(int i=1;i<=n;i++)
	scanf("%d",&t[in[i]]);
	root = new node(1,n);
	build(root,1,n);
	int q;
	scanf("%d",&q);
	while(q--){
		string s;
		int x;
		cin>>s>>x;
		if(s=="get"){
			printf("%d\n",query(root,in[x],out[x]));
		}
		else{
			revise(root,in[x],out[x]);
		}
	}
} 

//9
//      5
// 1 2 3 4     6 7 8 9