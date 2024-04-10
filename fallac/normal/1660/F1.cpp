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

#define MAX 101010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

struct fenwick {
	vector<int> tree;
	int N;
	fenwick() {}
	fenwick(int N) :N(N) {
		tree.resize(N + 1);
	}
	void update(int x, int a = 1) {
		while (x <= N) {
			tree[x] += a;
			x += (x & -x);
		}
	}
	int sum(int x) {
		x = max(0, x);
		x = min(N, x);
		int ans = 0;
		while (x) {
			ans += tree[x];
			x -= (x & -x);
		}
		return ans;
	}
};

int f(int x) {
	x %= 3;
	x += 30;
	return x % 3;
}

void solve() {
	int N;
	string s;
	cin >> N >> s;
	int i;
	fenwick bit[3];
	bit[0] = bit[1] = bit[2] = fenwick(N * 3 + 5);
	int bias = N + 5;
	int psum = 0;
	bit[0].update(0 + bias);
	ll ans = 0;
	for (i = 0; i < N; i++) {
		if (s[i] == '+') psum--;
		else psum++;
		ans += (ll)bit[f(psum)].sum(bias + psum);
		bit[f(psum)].update(bias + psum);
	}
	cout << ans << Ln;
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