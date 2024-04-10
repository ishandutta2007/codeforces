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
string s;
ll pre[300005][2];
ll nxt[300005][2];
int mx[300005];
int main(){
	cin >> s;
	rep(i,s.size()){
		rep(j,60){
			if(i+j >= s.size()) continue;
			if(s[i+j] == '0') nxt[i][0] |= (1LL<<j);
			else nxt[i][1] |= (1LL<<j);
		}
	}
	rep(i,s.size()){
		rep(j,60){
			if(i-j < 0) continue;
			if(s[i-j] == '0') pre[i][0] |= (1LL<<j);
			else pre[i][1] |= (1LL<<j);
		}
	}
	fill(mx,mx+300005,INF);
	rep(i,s.size()){
		int v  = s[i] - '0';
		int a = i-1, b = i+1;
		while(a>=0 && b<s.size()){
			ll X = pre[a][v] & nxt[b][v];
			if(X){
				rep(ii,60) if(((X>>ii)&1LL)){
					mx[a-ii] = min(mx[a-ii],b+ii);
					//cout << a-ii << " " << i << " " << b+ii << endl;
					goto nxt;
				}
			}
			a -= 60; b += 60;
		}
		nxt:;
	}
	ll ans = 0;
	ll ok = INF;
	for(int i=s.size()-1;i>=0;i--){
		ok = min(ok,1LL*mx[i]);
		ans += max(0LL,1LL*s.size()-ok);
	}
	cout << ans << endl;
}