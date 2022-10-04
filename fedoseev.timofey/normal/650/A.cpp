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
    ll ans = 0;
    map <int, int> cntx, cnty;
    map <pair <int, int>, int> cnt;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ++cntx[x];
        ++cnty[y];
        ++cnt[{x, y}];
    }
    for (auto &p : cntx) {
        ans += (ll)p.second * (p.second - 1) / 2;
    }
    for (auto &p : cnty) {
        ans += (ll)p.second * (p.second - 1) / 2;
    }
    for (auto &p : cnt) {
        ans -= (ll)p.second * (p.second - 1) / 2;
    }
    cout << ans << '\n';
}