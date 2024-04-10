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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    
    vector<int> s(2 * k + 10, 0);
    REP(i, n / 2) {
        s[2] += 2;
        s[2 * k + 1] -= 2;
        s[min(a[i], a[n - i - 1]) + 1] -= 1;
        s[max(a[i], a[n - i - 1]) + k + 1] += 1;
        s[a[i] + a[n - i - 1]] -= 1;
        s[a[i] + a[n - i - 1] + 1] += 1;
    }
    for (int i = 1; i < 2 * k + 10; ++i) {
        s[i] += s[i - 1];
    }
    int ans = n;
    for (int i = 2; i <= 2 * k; ++i) ans = min(ans, s[i]);
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    REP(_, t) solve();
}