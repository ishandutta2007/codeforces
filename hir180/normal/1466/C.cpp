//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
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
string str;
int dp[2][2][100005], n;
void solve(){
	cin >> str;
	if(str.size() == 1){
		cout << 0 << '\n';
		return;
	}
	else if(str.size() == 2){
		int ans = 0;
		if(str[0] == str[1]) ans = 1;
		cout << ans << '\n';
		return;
	}
	n = str.size();
	rep(i, 2){
		rep(j, 2){
			rep(k, n+3){
				dp[i][j][k] = INF;
			}
		}
	}
	rep(i, 2){
		rep(j, 2){
			dp[i][j][2] = i + j;
			if(i == 0 && j == 0 && str[0] == str[1]){
				dp[i][j][2] = INF;
			}
		}
	}
	for(int i=2;i<n;i++){
		rep(a, 2){
			rep(b, 2){
				if(dp[a][b][i] == INF) continue;
				bool bad = 0;
				if(b == 0 && str[i] == str[i-1]) bad = 1;
				if(a == 0 && str[i] == str[i-2]) bad = 1;
				if(!bad){
					chmin(dp[b][0][i+1], dp[a][b][i]);
				}
				chmin(dp[b][1][i+1], dp[a][b][i] + 1);
			}
		}
	}
	int ans = INF;
	rep(a, 2) rep(b, 2) chmin(ans, dp[a][b][n]);
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) solve();
}