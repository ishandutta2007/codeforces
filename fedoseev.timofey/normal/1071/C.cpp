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

const int K = 14;
const int L = 6;

vector <pair <int, int>> ans[1 << K];
vector <pair <int, int>> zer[1 << L];
bool have[1 << K];
bool vis[1 << L];

void precalc() {
    queue <int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int k = 0; k < L; ++k) {
            for (int d = 1; k - 2 * d >= L - K; ++d) {
                int j = k - d;
                int i = j - d;
                int y = x;
                if (i >= 0) y ^= (1 << i);
                if (j >= 0) y ^= (1 << j);
                y ^= (1 << k);
                if (!vis[y]) {
                    vis[y] = 1;
                    q.push(y);
                    zer[y] = zer[x];
                    zer[y].emplace_back(i, d);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    precalc();
    vector <pair <int, int>> res;
    while (n - 6 >= 8) {
        int mask = 0;
        int dt = n - 6;
        for (int i = n - 6; i < n; ++i) {
            if (a[i]) mask |= (1 << (i - dt));
        }
        for (auto &[i, d] : zer[mask]) {
            res.emplace_back(i + dt, d);
            int j = i + d;
            int k = j + d;
            if (j < 0) a[dt + j] ^= 1;
            if (i < 0) a[dt + i] ^= 1;
        }
        for (int i = 0; i < 6; ++i) a.pop_back();
        n -= 6;
    }
    queue <int> q;
    q.push(0);
    have[0] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < n; ++i) {
            for (int d = 1; i + 2 * d < n; ++d) {
                int j = i + d;
                int k = j + d;
                int y = x;
                y ^= (1 << i);
                y ^= (1 << j);
                y ^= (1 << k);
                if (!have[y]) {
                    have[y] = 1;
                    q.push(y);
                    ans[y] = ans[x];
                    ans[y].emplace_back(i, d);
                }
            }
        }
    }
    int mask = 0;
    for (int i = 0; i < n; ++i) if (a[i]) mask |= (1 << i);
    if (!have[mask]) {
        cout << "NO\n";
        return 0;
    }
    for (auto &[i, d] : ans[mask]) {
        res.emplace_back(i, d);
    }
    cout << "YES\n" << res.size() << '\n';
    for (auto &[i, d] : res) {
        int j = i + d;
        int k = j + d;
        cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << '\n';
    }
}