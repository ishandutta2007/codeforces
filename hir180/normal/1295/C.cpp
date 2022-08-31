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
string a,b;
vector<int>pos[26];

void solve(){
	cin >> a >> b;
	int n = a.size();
	rep(i,26) pos[i].clear();
	rep(i,n) pos[a[i]-'a'].pb(i);
	int fail = 0;
	int pre = -1;
	rep(i,b.size()){
		if(pos[b[i]-'a'].empty()){ puts("-1"); return ;}
		int id = POSU(pos[b[i]-'a'],pre);
		if(id == pos[b[i]-'a'].size()) { fail++; pre = pos[b[i]-'a'][0]; }
		else pre = pos[b[i]-'a'][id];
	}
	cout << fail+1 << '\n';
}
int main(){
	cin >> t;
	while(t--) solve();
}