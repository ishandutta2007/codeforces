#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 7;

vector <int> g[N];

int cnt[N][2];

int n;

int kek = 0;
void dfs(int u, bool fl = 0, int p = -1) {
	++cnt[u][0];
	if (fl) ++kek;
	for (auto v : g[u]) {
		if (v != p) {
			dfs(v, fl ^ 1, u);
			cnt[u][0] += cnt[v][1];
			cnt[u][1] += cnt[v][0];
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    for (int i = 0; i + 1 < n; ++i) {
    	int u, v;
    	cin >> u >> v;
    	--u, --v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    dfs(0);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
    	sum += (ll)(cnt[i][0] + cnt[i][1]) * (n - (cnt[i][0] + cnt[i][1]));
    }
    ll odd = (ll)kek * (n - kek);
    cout << (sum - odd) / 2 + odd << '\n';
}