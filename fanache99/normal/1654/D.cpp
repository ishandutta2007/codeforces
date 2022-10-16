#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

const int MAXN = 200000;
const int MOD = 998244353;

vector<pair<int, pair<int, int> > > g[1 + MAXN];
int low[1 + MAXN];

void precompute(int n) {
    for (int i = 2; i <= n; i++) {
        if (low[i] == 0) {
            for (int j = i; j <= n; j += i) {
                if (low[j] == 0) {
                    low[j] = i;
                }
            }
        }
    }
}

vector<pair<int, int> > decompose(int x) {
    vector<pair<int, int> > ans;
    while (x > 1) {
        int d = low[x];
        ans.push_back({d, 0});
        while (low[x] == d) {
            x /= d;
            ans.back().second++;
        }
    }
    return ans;
}

int power(int base, int power) {
    int ans = 1;
    while (power) {
        if (power & 1) {
            ans = 1LL * ans * base % MOD;
        }
        base = 1LL * base * base % MOD;
        power >>= 1;
    }
    return ans;
}

int worst[1 + MAXN], current[1 + MAXN];

void DFS(int node, int father) {
    for (auto &[son, it] : g[node])
        if (son != father) {
            auto [x, y] = it;
            vector<pair<int, int> > xd = decompose(x), yd = decompose(y);
            for (auto [d, p] : xd) {
                current[d] -= p;
            }
            for (auto [d, p] : yd) {
                current[d] += p;
                worst[d] = max(worst[d], current[d]);
            }
            DFS(son, node);
            for (auto [d, p] : xd) {
                current[d] += p;
            }
            for (auto [d, p] : yd) {
                current[d] -= p;
            }
        }
}

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

void solve(int node, int father, int base, int &ans) {
    add(ans, base);
    for (auto &[son, it] : g[node])
        if (son != father) {
            auto[x, y] = it;
            solve(son, node, 1LL * base * x % MOD * power(y, MOD - 2) % MOD, ans);
        }
}

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();

    precompute(MAXN);

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 1; i < n; i++) {
            int a, b, x, y;
            cin >> a >> b >> x >> y;
            g[a].push_back({b, {y, x}});
            g[b].push_back({a, {x, y}});
        }
        DFS(1, 0);
        int base = 1;
        for (int i = 1; i <= n; i++) {
            base = 1LL * base * power(i, worst[i]) % MOD;
        }
        int ans = 0;
        solve(1, 0, base, ans);
        cout << ans << "\n";
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            worst[i] = 0;
            current[i] = 0;
        }
    }



    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
//    cout << duration.count() << "\n";
    return 0;
}