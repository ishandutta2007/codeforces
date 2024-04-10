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
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(0); cin.tie(0);
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> diff(n);
    set <int> cur;
    for (int i = n - 1; i >= 0; --i) {
        cur.insert(a[i]);
        diff[i] = cur.size();
    }
    set <int> used;
    ll ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (!used.count(a[i])) {
            used.insert(a[i]);
            ans += diff[i + 1];
        }
    }
    cout << ans << '\n';
}