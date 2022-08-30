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
typedef pair<Q,ll> R;
int n;
ll aa[200005], a[200005], b[200005];

//OK....
map<ll,ll>M;
int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%lld",&aa[i]);
	ll pre = 1e15;
	int id = 0;
	rep(i,n){
		if(pre > aa[i]){
		    pre = aa[i];
			a[id] = aa[i];
			b[id++] = 1;
		}
		else{
			b[id-1]++;
		}
	}
	n = id;

	//[-INF,a[0]-1]  b[0] * x + 0
	M[1-a[0]] = 0;
	ll cur = b[0];
	
	for(int i=1;i<n;i++){
		while(!M.empty() && -(*M.begin()).fi >= a[i]){
			pair<ll,ll>q = (*M.begin()); M.erase(M.begin());
			//[-INF, -q.fi]  cur * x + q.sc
			ll R = -q.fi;
			ll mx = (R/a[i]) * a[i];
			//[-INF, a[i]-1]  cur * x + q.sc + (mx-a[i]) * cur
			M[1-a[i]] = max(M[1-a[i]], q.sc + (mx-a[i]) * cur);
			//[-INF, R%a[i]]  cur * x + q.sc + mx * cur
			M[-(R%a[i])] = max(M[-(R%a[i])], q.sc + mx * cur);
		}
		cur += b[i];
	}
	ll ans = 0;
	for(auto a:M){
		if(a.fi == 1) continue;
		ans = max(ans,cur * (-a.fi) + a.sc);
	}
	cout << ans << '\n';
}