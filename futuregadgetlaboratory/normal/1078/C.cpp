#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
	const int maxn = 131072;
	static char buf[maxn],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
	int res(0);
	char c = getchar();
	while(c < '0') c = getchar();
	while(c >= '0') {
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return res;
}

inline int fastpo(int x, int n, int mod) {
	int res(1);
	while(n) {
		if(n & 1) {
			res = res * (LL)x % mod;
		}
		x = x * (LL) x % mod;
		n /= 2;
	}
	return res;
}
const int N = 300033;
const int LOG = 20;
const int mod = 998244353;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> adj[N];
int fa[N], pw[N];
int dp[N][3];
int inv(int x) {
	return x == 1 ? 1 : (LL)inv(x - mod % x) * ((mod + x - 1) / x) % mod;
}
int main() {
	int n;
	scanf("%d", &n);
	pw[0] = 1;
	for(int i(1); i <= n; i++) pw[i] = pw[i - 1] * 2 % mod;
	for(int i(1); i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<int> q;
	q.push_back(1);
	fa[1] = 0;
	for(int op(0); op < (int)q.size(); op++) {
		int v = q[op];
		for(int y : adj[v]) {
			if(y != fa[v]) {
				fa[y] = v;
				q.push_back(y);
			}
		}
	}
	
	for(int i(n - 1); i >= 0; i--) {
		int v = q[i];
		int cnt = 0;
		int pi = 1;
		for(int y : adj[v]) {
			if(y == fa[v]) continue;
			cnt++;
			pi = (LL)pi * (dp[y][0] + dp[y][2]) % mod;
		}
		dp[v][1] = pi % mod;
		dp[v][0] = 0;
		for(int y : adj[v]) {
			if(y == fa[v]) continue;
			dp[v][0] = (dp[v][0] + (LL)pi % mod * inv((dp[y][0] + dp[y][2]) % mod) % mod * dp[y][1]) % mod;
		}
		dp[v][2] = 1;
		for(int y : adj[v]) {
			if(y == fa[v]) continue;
			dp[v][2] = (LL)dp[v][2] * dp[y][2] % mod;
		}
		dp[v][2] = (dp[v][2] + dp[v][0]) % mod;
	}
	cout << dp[1][2] << endl;
}