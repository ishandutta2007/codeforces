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
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        REP(i, n) cin >> a[i];
        sort(ALL(a));
        ll sum = 0, ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            sum += a[i] - x;
            if(sum >= 0) ans++;
            else break;
        }
        cout << ans << "\n";
    }
    return 0;
}