/*

*/

#include <bits/stdc++.h>
#include <cassert>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 201010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

vector<int> adj[MAX];
int ans[MAX];
int A[MAX];
int B[MAX];
vector<ll> psum;

void dfs(int x, ll sum = 0) {
	ans[x] = upper_bound(psum.begin(), psum.end(), sum) - psum.begin() - 1;
	for (auto v : adj[x]) {
		psum.push_back((ll)B[v] + psum.back());
		dfs(v, sum + A[v]);
		psum.pop_back();
	}
}

void solve() {
	int N;
	cin >> N;
	int i;
	for (i = 1; i <= N; i++) adj[i].clear();
	for (i = 2; i <= N; i++) {
		int p;
		cin >> p >> A[i] >> B[i];
		adj[p].push_back(i);
	}
	psum.clear();
	psum.push_back(0);
	dfs(1);
	for (i = 2; i <= N; i++) cout << ans[i] << bb;
	cout << ln;
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	while (T--) {
		init();
		solve();
	}
}