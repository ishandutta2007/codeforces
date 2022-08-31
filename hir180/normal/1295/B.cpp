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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
 
const ll mod = 1000000007;
int t;
int n,x;
string s;
int rui[100005];
int cnt[300005];
 
void solve(){
	cin >> n >> x >> s;
	rep(i,n){
		rui[i+1] = rui[i] + (s[i]=='0'?1:-1);
	}
	rep(i,2*n+5) cnt[i] = 0;
	rep(i,n) cnt[rui[i]+n+2]++;
	if(rui[n] == 0){
	    if(n+x+2 >= 0 && n+x+2 < 2*n+5 && cnt[n+x+2]) puts("-1");
	    else puts("0");
	}
	else{
		int k ;
		if(x <= 0 && rui[n] < 0) k = abs(x)/abs(rui[n]);
		else if(x >= 0 && rui[n] > 0) k = abs(x)/abs(rui[n]);
		else k = 0;
		ll ans = 0;
		for(int xx=k-10*n;xx<=k+10*n;xx++){
			if(xx < 0) continue;
			ll zan = 1LL * x - 1LL * rui[n] * xx;
			if(zan+n+2 >= 0 && zan+n+2 < 2*n+5) ans += cnt[zan+n+2];
		}
		cout<<ans<<'\n';
	}
}
int main(){
	cin >> t;
	while(t--) solve();
}