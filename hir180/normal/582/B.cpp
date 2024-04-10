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
#define per(i,x) for(int i=x-1;i>=0;i--)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
int n,tt,a[105],dp[25][102][102],dp_conv[25][102][102],t[105][105],ans[2][105];
vector<int>za;

int main(){
	cin >> n >> tt;
	rep(i,n){
		cin >> a[i];
		za.pb(a[i]);
	}
	SORT(za); ERASE(za);
	rep(i,n){
		a[i] = POSL(za,a[i]);
	}
	rep(i,25)rep(j,102)rep(k,102) dp[i][j][k] = dp_conv[i][j][k] = -INF;
	//calc dp[0]
	rep(x,n){
		rep(i,105) rep(j,105) t[i][j] = -INF;
		t[x][a[x]] = 0;
		for(int i=x;i<n;i++){
			rep(j,za.size()){
				if(t[i][j] < 0) continue;
				if(j <= a[i]){
					chmax(t[i+1][a[i]], t[i][j]+1);
				}
				chmax(t[i+1][j], t[i][j]);
			}
		}
		rep(j,za.size()) dp[0][a[x]][j] = max(dp[0][a[x]][j], t[n][j]);
	}
	rep(k,24){
		rep(a,za.size()){
			rep(b,za.size()){
				rep(c,a+1){
					chmax(dp_conv[k][c][b], dp[k][a][b]);
				}
			}
		}
		rep(i,za.size()){
			rep(a,za.size()){
				rep(b,za.size()){
					chmax(dp[k+1][a][b], dp[k][a][i]+dp_conv[k][i][b]);
				}
			}
		}
	}
	rep(p,2) rep(i,105) ans[p][i] = -INF;
	ans[0][0] = 0;
	int cur = 0, nxt = 1;
	
	rep(k,24){
		if(((tt>>k)&1) == 0) continue;
		rep(i,za.size()) ans[nxt][i] = -INF;
		rep(i,za.size()){
			rep(j,za.size()){
				ans[nxt][j] = max(ans[nxt][j], ans[cur][i]+dp_conv[k][i][j]);
			}
		}
		swap(cur,nxt);
	}
	
	int ret = -INF;
	rep(i,za.size()) ret = max(ret,ans[cur][i]);
	cout<<ret<<endl;
}