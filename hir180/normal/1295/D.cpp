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
ll a,m;
vector<ll>dv,way;
ll gcdd(ll a,ll b){
	if(a < b) swap(a,b);
	if(b == 0) return a;
	else return gcdd(b,a%b);
}
void solve(){
	cin >> a >> m; dv.clear();
	for(ll i=1;i*i<=m;i++){
		if(m%i != 0) continue;
		dv.pb(i);
		if(i*i != m) dv.pb(m/i);
	}
	SORT(dv);
	ll x = gcdd(a,m);
	way.resize(dv.size(),0);
	for(int i=dv.size()-1;i>=0;i--){
		//a + ? = 0 (mod dv[i])
		way[i] = ((-a)%dv[i]+dv[i])%dv[i];
		if(way[i] >= m) way[i] = 0;
		else{
			way[i] = (m-1-way[i]) / dv[i] + 1;
		}
		for(int j=i+1;j<dv.size();j++){
			if(dv[j]%dv[i] == 0) way[i] -= way[j];
		}
		if(x == dv[i]){
			cout << way[i] << endl;
			return;
		}
	}
}
int main(){
	cin >> t;
	while(t--) solve();
}