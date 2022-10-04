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

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

int l[N], r[N], q[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i] >> q[i];
        --l[i], --r[i];
    }
    vector <int> ans(n);
    for (int b = 0; b < 30; ++b) {
        vector <int> p(n + 1);
        for (int i = 0; i < m; ++i) {
            if (q[i] & (1 << b)) {
                ++p[l[i]];
                --p[r[i] + 1];
            }
        }
        for (int i = 1; i < n; ++i) {
            p[i] += p[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            if (p[i]) {
                ans[i] += (1 << b);
                p[i] = 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            p[i] += p[i - 1];
        }
        for (int i = 0; i < m; ++i) {
            if (!(q[i] & (1 << b))) {
                if (p[r[i]] - (l[i] == 0 ? 0 : p[l[i] - 1]) == r[i] - l[i] + 1) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}