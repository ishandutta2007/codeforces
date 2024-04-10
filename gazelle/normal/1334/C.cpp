#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cassert>
#include <random>
#include <iomanip>
#include <bitset>
#define FOR(i, n, m) for(ll i = n; i < (int)m; i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 998244353;
constexpr long double eps = 1e-9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    REP(testcase, t) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        REP(i, n) cin >> a[i] >> b[i];
        REP(i, n) b[i] = min(b[i], a[(i + 1) % n]);
        ll mn = b[0];
        REP(i, n) mn = min(mn, b[i]);
        ll ans = 0;
        REP(i, n) ans += a[i] - b[i];
        ans += mn;
        cout << ans << "\n";
    }
    return 0;
}