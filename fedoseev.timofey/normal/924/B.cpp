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
    int n, u;
    cin >> n >> u;
    vector <int> e(n);
    for (int i = 0; i < n; ++i) {
        cin >> e[i];
    }
    double ans = -1;
    for (int i = 1; i + 1 < n; ++i) {
        int x = e[i - 1];
        int l = i;
        int r = n;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (e[m] - x <= u) l = m;
            else r = m;
        }
        if (l != i) ans = max(ans, (double)(e[l] - e[i]) / (e[l] - x));
    }
    if (ans == -1) {
        cout << -1 << endl;
        return 0;
    }
    cout << fixed << setprecision(16) << ans << endl;
}