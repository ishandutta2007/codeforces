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

const int N = 1e5 + 7;

int deg[N];
set <int> g[N];
int cnt[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    if (k > 100) {
        cout << "No\n";
        return 0;
    }
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        ++deg[u];
        ++deg[v];
        g[u].insert(v);
        g[v].insert(u);
    }
    int who = -1;
    int number = n;
    for (int j = 1; j <= k; ++j) {
        if (number == 1) {
            cout << "No\n";
            return 0;
        }
        set <int> idx;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1) {
                idx.insert(i);
            }
        }
        if (idx.empty()) {
            cout << "No\n";
            return 0;
        }
        vector <int> jdx;
        for (auto i : idx) {
            --number;
                int p = *g[i].begin();
                jdx.push_back(p);
                if (idx.count(p)) {
                    cout << "No\n";
                    return 0;
                }
                ++cnt[p];
                --deg[p];
                if (deg[p] == 0) {
                    if (who != -1) {
                        cout << "No\n";
                        return 0;
                    }
                    who = p;
                }
                --deg[i];
                g[i].erase(p);
                g[p].erase(i);
        }
        for (auto j : jdx) {
            if (deg[j] > 1) {
                cout << "No\n";
                return 0;
            }
        }
    }
    if (number != 1 || who == -1) {
        cout << "No\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (cnt[i] != 0 && cnt[i] < 3) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}