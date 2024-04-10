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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(m, vector <int> (n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            --a[i][j];
        }
    }
    vector <int> uk(m);
    vector <vector <int>> where(m, vector <int> (n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            where[i][a[i][j]] = j;
        }
    }
    ll ans = 0;
    for (int l = 0; l < n; ++l) {
        for (int i = 0; i < m; ++i) {
            uk[i] = where[i][a[0][l]];
        }
        bool ok = true;
        while (ok) {
            int x = uk[0];
            if (x == n - 1) {
                ok = false;
                break;
            }
            int cur = a[0][x + 1];
            for (int i = 0; i < m; ++i) {
                if (uk[i] == n - 1) {
                    ok = false;
                    break;
                }
                if (a[i][uk[i] + 1] != cur) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
            for (int i = 0; i < m; ++i) {
                ++uk[i];
            }
        }
        ans += (ll)(uk[0] - l + 1) * (uk[0] - l + 2) / 2;
        l = uk[0];
    }
    cout << ans << '\n';
}