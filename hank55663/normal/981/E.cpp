#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define last Last
using namespace std;
typedef long long LL;
struct node{
	int a,b;
	node *l,*r;
	vector<int> v;
	node(int _a,int _b):l(NULL),r(NULL){
		a=_a;
		b=_b;
	}
}*root;
void build(node *n){
	if(n->a==n->b)
	return;
	int mid=(n->a+n->b)/2;
	n->l=new node(n->a,mid);
	n->r=new node(mid+1,n->b);
	build(n->l);
	build(n->r);
}
void add(node *n,int l,int r,int k){
	if(n->a>=l&&n->b<=r){
		n->v.pb(k);
		return ;
	}
	if(n->b<l)
	return;
	if(n->a>r)
	return ;
	add(n->l,l,r,k);
	add(n->r,l,r,k);
}
bitset<20000>ans;
void travel(node *n,bitset<20000> res){

	for(auto it:n->v)
	res|=res<<it;
	if(n->a!=n->b){
		travel(n->l,res);
		travel(n->r,res);
	}
	ans|=res;
}
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	root=new node(1,n);
	build(root);
	while(q--){
		int l,r,x;
		scanf("%d %d %d",&l,&r,&x);
		add(root,l,r,x);
	}
	bitset<20000> x;
	x[0]=1;
	travel(root,x);
	vector<int> v;
	for(int i=1;i<=n;i++)
	if(ans[i])
	v.pb(i);
	printf("%d\n",v.size());
	for(auto it:v)
	printf("%d ",it);
}