#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cassert>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    ll ans = 0;
    int mx = a[0];
    for (int i = 1; i < n; ++i) {
        if ((a[i - 1] < 0 && a[i] > 0) || (a[i - 1] > 0 && a[i] < 0)) {
            ans += mx;
            mx = a[i];
        } else {
            mx = max(mx, a[i]);
        }
    }
    ans += mx;
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    REP(_, t) solve();
}