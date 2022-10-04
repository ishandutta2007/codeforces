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
    int n, a, b;
    cin >> n >> a >> b;
    map <pair <int, int>, int> both;
    map <ll, int> cnt;
    for (int i = 0; i < n; ++i) {
        int x, Vx, Vy;
        cin >> x >> Vx >> Vy;
        ++both[{Vx, Vy}];
        ++cnt[(ll)a * Vx - Vy];
    }
    ll ans = 0;
    for (auto p : cnt) {
        ans += (ll)p.second * (p.second - 1);
    }
    for (auto p : both) {
        ans -= (ll)p.second * (p.second - 1);
    }
    cout << ans << '\n';
}