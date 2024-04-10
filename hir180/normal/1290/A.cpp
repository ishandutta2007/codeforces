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

int t,n,m,k,a[5005];

void solve(){
	cin >> n >> m >> k;
	repn(i,n) cin >> a[i];
	int ans = 0;
	for(int num=0;num<=k&&num<=m-1;num++){
		if(num < k && num < m-1) continue;
		
		for(int L=0;L<=num;L++){
			int R = num-L;
			int zan = m-1-num;
			int add = INF+5;
			rep(x,zan+1){
				int le = a[L+x+1];
				int ri = a[n-R-zan+x];
				add = min(add,max(le,ri));
			}
			if(add <= INF) ans = max(ans,add);
		}
	}
	cout << ans << endl;
}
int main(){
	cin >> t;
	while(t--) solve();
}