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
        ll n, l, r;
        cin >> n >> l >> r;
        if(l == n * (n - 1) + 1) {
            cout << 1 << "\n";
            continue;
        }
        
        ll top = 1, sum = 0;
        while(sum + 2 * (n - top) < l) {
            sum += 2 * (n - top);
            top++;
        }
        bool b = false; if(r == n * (n - 1) + 1) {
            b = true;
            r--;
        }
        vector<ll> ans;
        ll idx = sum + 1;
        while(1) {
            REP(i, n - top) {
                if(l <= idx && idx <= r) ans.pb(top);
                idx++;
                if(l <= idx && idx <= r) ans.pb(top + i + 1);
                idx++;
            }
            if(idx > r) break;
            top++;
        }
        if(b) ans.pb(1);
        REP(i, ans.size()) {
            if(i) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}