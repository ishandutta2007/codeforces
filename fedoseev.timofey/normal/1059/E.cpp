#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 7;
const int K = 20;
vector <int> g[N];

ll sum[K][N];
int go[K][N];

int a[N];

int l;
ll S;

void dfs(int u, int p = 0) {
	go[0][u] = p;
	for (int k = 1; k < K; ++k) {
		go[k][u] = go[k - 1][go[k - 1][u]];
	}
	sum[0][u] = a[u];
	for (int k = 1; k < K; ++k) {
		sum[k][u] = sum[k - 1][u] + sum[k - 1][go[k - 1][u]];
	}
	for (auto v : g[u]) {
		if (v != p) dfs(v, u);
	}
}

int dp[N];
int can[N];

int get(int u) {
	int cnt = 0;
	ll cS = 0;
	for (int k = K - 1; k >= 0; --k) {
		if (cnt + (1 << k) <= l && sum[k][u] + cS <= S) {
			cS += sum[k][u];
			cnt += (1 << k);
			u = go[k][u];
		}
	}
	return cnt;
}

void jhfs(int u, int p = -1) {
	int mx = 0;
	for (auto v : g[u]) {
		if (v != p) {
			jhfs(v, u);
			dp[u] += dp[v];
			mx = max(mx, can[v]);
		}
	}
	if (mx) {
		can[u] = mx - 1;
	}
	else {
		++dp[u];
		can[u] = get(u) - 1;
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n >> l >> S;

    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    	if (a[i] > S) {
    		cout << "-1\n";
    		return 0;
    	}
    }

    for (int i = 1; i < n; ++i) {
    	int p;
    	cin >> p;
    	--p;
    	g[p].push_back(i);
    }

    dfs(0);
    jhfs(0);

    cout << dp[0] << '\n';
}