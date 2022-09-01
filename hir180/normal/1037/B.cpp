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
#define ld long double
const int mod = 998244353;
int n;
ll a;
vector<ll>vec;
int main(){
	ios::sync_with_stdio(false); 
	cin >> n >> a;
	vec.resize(n);
	rep(i,n){ cin >> vec[i]; }
	SORT(vec);
	int m = n/2;
	ll ans = 0;
	rep(i,m) ans += max(0LL,vec[i]-a);
	ans += abs(vec[m]-a);
	for(int i=m+1;i<n;i++) ans += max(0LL,a-vec[i]);
	cout << ans << endl;
}