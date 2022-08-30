//Let's join Kaede Takagaki Fun Club !!
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
#define all(x) x.begin(),x.end()
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
template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}

ll aa[3][3];
int n;
ll dp[3][3][44];
int main(){
	rep(i,3)rep(j,3) cin >> aa[i][j];
	cin >> n;
	rep(i,3)rep(j,3){
	    if(i == j) continue;
		dp[i][j][1] = aa[i][j];
		chmin(dp[i][j][1], aa[i][3-i-j] + aa[3-i-j][j]);
	}
	for(int i=2;i<=n;i++){
		rep(a,3)rep(b,3){
		    if(a == b) continue;
			//dp[a][b][i]
			int c = 3-a-b;
			dp[a][b][i] = dp[a][c][i-1] + aa[a][b] + dp[c][b][i-1];
			chmin(dp[a][b][i], 2LL*dp[a][b][i-1] + aa[a][c] + dp[b][a][i-1] + aa[c][b]);
		}
	}
	cout << dp[0][2][n] << endl;
}