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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    if (n <= 2) {
        cout << 0 << '\n';
        return 0;
    }
    int ans = 1e9;
    for (int d1 = -1; d1 <= 1; ++d1) {
        for (int d2 = -1; d2 <= 1; ++d2) {
            int res = (d1 != 0) + (d2 != 0);
            int x = (b[1] + d2) - (b[0] + d1);
            vector <int> a = b;
            a[1] += d2;
            bool bad = false;
            for (int i = 2; i < n; ++i) {
                int need = x - (a[i] - a[i - 1]);
                if (need == 0) continue;
                if (need == -1 || need == 1) {
                    a[i] += need;
                    ++res;
                }
                else {
                    bad = 1;
                    break;
                }
            }
            if (!bad) {
                ans = min(ans, res);
            }
        }
    }
    if (ans > 1e8) {
        cout << -1 << '\n';
    }
    else {
        cout << ans << '\n';
    }
}