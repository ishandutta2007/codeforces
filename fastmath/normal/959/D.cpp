#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <bitset>

using namespace std;

const int MAXN = 1e5 + 7;
const int MAXV = 1500000;

int a[MAXN];
vector <int> d[MAXV];
bool p[MAXV];
bool used[MAXV];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < MAXV; ++i) p[i] = true;
    for (int i = 2; i < MAXV; ++i) {
        if (p[i]) {
            d[i].push_back(i);
            for (int j = 2 * i; j < MAXV; j += i) {
                p[j] = false;
                d[j].push_back(i);
            }
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        bool check = true;
        for (int j : d[a[i]]) if (used[j]) check = false;
        if (!check) break;
        for (int j : d[a[i]]) used[j] = true;
        pos = max(pos, i);
    }

    for (int i = 0; i <= pos; ++i) cout << a[i] << ' ';
    if (pos == n - 1) return 0;

    for (int i = a[pos + 1] + 1; ; ++i) {
        bool check = true;
        for (int j : d[i]) {
            check &= !used[j];
        }   
        if (check) {
            cout << i << ' ';
            for (int j : d[i]) used[j] = true;
            break;
        }
    }

    int u = 2;
    for (int i = pos + 2; i < n; ++i) {
        while (!p[u] || used[u]) ++u;
        cout << u << ' ';
        used[u] = true;
    }

    cout << '\n';
    return 0;
}