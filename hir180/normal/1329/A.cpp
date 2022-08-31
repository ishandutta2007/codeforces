//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
#define int long long
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
int n, m, a[100005], dp[2][100005], ans[100005];
signed main(){
	cin >> n >> m;
	repn(i, m) cin >> a[i];
	dp[0][0] = n, dp[1][0] = n;
	repn(i, m){
		dp[0][i] = dp[0][i-1] - a[i];
		dp[1][i] = dp[1][i-1] - 1;
	}
	int las = 0;
	for(int i=m;i>=1;i--){
		if(las < dp[0][i] || las > dp[1][i]){
			puts("-1"); return 0;
		}
		int nxt = max(las+1, a[i]);
		if(nxt < dp[0][i-1]) nxt = min(las+a[i], dp[1][i-1]);
		ans[i] = nxt; las = nxt;
	}
	if(las > n){
		puts("-1"); return 0;
	}
	for(int i=1;i<=m;i++){
		printf("%d ", ans[i] - a[i] + 1);
	}
	puts("");
}