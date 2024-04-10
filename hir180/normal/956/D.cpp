#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
typedef pair<ll,ll> Q;

int n;
ll w,x[100005],v[100005];
vector<Q>za;
Q pre[100005],nxt[100005];
vector<int>query[200005];

bool cmp(const Q &a,const Q &b){
	return a.fi * b.sc < a.sc * b.fi;
}
void norm(Q &a){
	ll x = __gcd(a.fi,a.sc);
	a.fi /= x; a.sc /= x;
}

struct BIT
{
	int bit[200005];
	int f(int x)
	{
		return x&-x;
	}
	void add(int i,int x)
	{
		i++;
		for(int s=i;s<200005;s+=f(s)) bit[s]+=x;
	}
	int sum(int i)
	{
		i++;
		int res=0;
		for(int s=i;s>0;s-=f(s)) res+=bit[s];
		return res;
	}
}kaede;

/*int findd(vector<Q>&v,Q &a){
    int lb = 0, ub = v.size();
    while(ub - lb > 1){
        int mid = (lb+ub)/2;
        if(cmp(a,v[mid])) ub = mid;
        else lb = mid;
    }
    return lb;
}*/

int main(){
	scanf("%d%lld",&n,&w);
	repn(i,n){
		scanf("%lld%lld",&x[i],&v[i]);
		x[i] = abs(x[i]);
		pre[i] = mp(x[i],abs(v[i]-w));
		nxt[i] = mp(x[i],abs(v[i]+w));
		norm(pre[i]); norm(nxt[i]);
		za.pb(pre[i]); za.pb(nxt[i]);
	}
	sort(za.begin(),za.end(),cmp);
	za.erase(unique(za.begin(),za.end()),za.end());
	repn(i,n){
		int x = lower_bound(za.begin(),za.end(),pre[i],cmp)-za.begin();
		int y = lower_bound(za.begin(),za.end(),nxt[i],cmp)-za.begin();

		query[x].pb(y);
	}
	
	ll ans = 1LL * n * (n-1) / 2;
	rep(i,za.size()){
		rep(j,query[i].size()){
			int x = query[i][j];
			ans -= kaede.sum(x-1);
		}
		rep(j,query[i].size()){
			int x = query[i][j];
			kaede.add(x,1);
		}
		
	}
	cout << ans << '\n' ;
}