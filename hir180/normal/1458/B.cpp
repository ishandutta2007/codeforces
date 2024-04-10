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
int n, a[105], b[105], all;
int dp[2][105][10005], ans[105];

int main(){
	cin >> n;
	repn(i,n) cin >> a[i] >> b[i];
	repn(i,n) all+=b[i];
	rep(i,2)rep(j,105)rep(k,10005) dp[i][j][k] = -INF;
	dp[0][0][0] = 0;
	int cur = 0, nxt = 1;
	repn(i, n){
		rep(j, 105) rep(k,10005) dp[nxt][j][k] = -INF;
		rep(j, 105) rep(k,10005){
		    if(dp[cur][j][k] < 0) continue;
			chmax(dp[nxt][j][k], dp[cur][j][k]);
			chmax(dp[nxt][j+1][k+a[i]], dp[cur][j][k] + b[i]);
		}
		swap(cur, nxt);
	}
	rep(j,105)rep(k,10005){
		if(dp[cur][j][k] < 0) continue;
		chmax(ans[j], dp[cur][j][k]*2+min(2 * (k-dp[cur][j][k]) , all-dp[cur][j][k]));
	}
	repn(i, n){
		printf("%.9f ", (double)(ans[i])/2.0);
	}
	puts("");
}