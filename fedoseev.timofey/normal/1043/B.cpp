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
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> b(n);
    b[0] = a[0];
    for (int i = 1; i < n; ++i) b[i] = a[i] - a[i - 1];

    vector <int> ans;
    for (int x = 1; x <= n; ++x) {
        bool fl = true;
        for (int i = 0; i < (n + x - 1) / x; ++i) {
            for (int j = 0; j < x; ++j) {
                if (i * x + j < n && b[j] != b[i * x + j]) {
                    fl = false;
                    break;
                }
            }
            if (!fl) break;
        }
        if (fl) ans.push_back(x);
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
}