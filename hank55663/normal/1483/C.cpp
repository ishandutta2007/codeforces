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
#define index Index
using namespace std;
struct node{
	node *l,*r;
	int a,b;
	LL Max;
	node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),Max(-1e9){

	}
}*root;
void pull(node *n){
	n->Max=max(n->l->Max,n->r->Max);
}
void build(node *n){
	if(n->a==n->b)return;
	int mid=(n->a+n->b)/2;
	n->l=new node(n->a,mid);
	n->r=new node(mid+1,n->b);
	build(n->l);
	build(n->r);
}
LL query(node *n,int l,int r){
	if(n->a>=l&&n->b<=r)return n->Max;
	if(n->b<l||n->a>r)return -1e9-10;
	return max(query(n->l,l,r),query(n->r,l,r));
}
void ass(node *n,int x,LL w){
	if(n->a==n->b){
		n->Max=w;
		return;
	}
	int mid=(n->a+n->b)/2;
	if(x<=mid)ass(n->l,x,w);
	else ass(n->r,x,w);
	pull(n);
}
bool solve(){
	int n;
	scanf("%d",&n);
	int h[300005];
	int b[300005];
	LL dp[300005];
	dp[0]=0;
	for(int i = 1;i<=n;i++)scanf("%d",&h[i]);
	for(int i = 1;i<=n;i++)scanf("%d",&b[i]);
	vector<pair<int,pll> > v;
	v.pb(mp(0,mp(0,0)));
	multiset<LL> s;
	root=new node(0,n);
	build(root);
	ass(root,0,0);
	for(int i = 1;i<=n;i++){
		while(v.back().x>h[i]){
			s.erase(s.find(v.back().y.y));
			v.pop_back();
		}
		LL x=query(root,v.back().y.x,i-1);
		v.pb(mp(h[i],mp(i,x+b[i])));
		s.insert(x+b[i]);
		dp[i]=*s.rbegin();
		ass(root,i,dp[i]);
	}
	printf("%lld\n",dp[n]);
	return true;
}
int main(){
	int t=1;//000000;
	//scanf("%d",&t);
	while(t--)solve();
}