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
int q;
int main(){
	cin >> q;
	while(q--){
		int n,r; cin >> r >> n;
		vector<int>vi;
		rep(i,n){
			int a; scanf("%d",&a); vi.pb(a);
		}
		int look = 1;
		while(vi.size() && vi.back() == look){
			vi.pop_back(); look++;
		}
		if(vi.empty()){ cout << 0 << endl; }
		else{
			vector<int>vecc;
			int cur = r+1;
			int len = 0;
			rep(i,vi.size()){
				if(cur == vi[i]+1){
					cur--; len++;
				}
				else{
					vecc.pb(len);
					len = 1;
					cur = vi[i];
				}
			}
			vecc.pb(len);
			int ans = 0;
			if(vecc[0]%2 == 0) ans++;
			for(int i=1;i<vecc.size();i++) if(vecc[i]%2 == 1) ans++;
			cout << ans << endl;
		}
	}
}