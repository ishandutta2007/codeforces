#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int,int> TP;
typedef vector<vector<ll>> mat;
const int N=2e5+5;
const ll mod=1e9+7;
int n;
ll s[N],lazy[4*N];
pll tree[4*N];  // max ( sum(Ai) - Si )
ll a[N];
void pushdown(int nd,int l,int r)
{
	tree[nd].fi+=lazy[nd];
	if(l!=r){
		lazy[nd*2]+=lazy[nd];
		lazy[nd*2+1]+=lazy[nd];
	}
	lazy[nd]=0;
}
void upd1(int nd,int l,int r,int s,int e,ll v)
{
	pushdown(nd,l,r);
	if(r<s||e<l) return;
	if(s<=l&&r<=e){
		lazy[nd]=v;
		pushdown(nd,l,r);
		return;
	}
	int m=(l+r)/2;
	upd1(nd*2,l,m,s,e,v);
	upd1(nd*2+1,m+1,r,s,e,v);
	tree[nd]=max(tree[nd*2],tree[nd*2+1]);
}
void build(int nd,int l,int r)
{
	if(l==r){
		tree[nd]=pll(-s[l],l);
		return;
	}
	int m=(l+r)/2;
	build(nd*2,l,m); build(nd*2+1,m+1,r);
	tree[nd]=max(tree[nd*2],tree[nd*2+1]);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	build(1,1,n);
	for(ll i=1;i<=n;i++){
		pushdown(1,1,n);
		pll pr=tree[1];
		int idx=pr.se;
		if(a[idx]) assert(0);
		a[idx]=i;
		upd1(1,1,n,idx,idx,-1e15-pr.fi);
		upd1(1,1,n,idx+1,n,i);
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}