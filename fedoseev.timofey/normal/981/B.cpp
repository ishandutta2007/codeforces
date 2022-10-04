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
    int n;
    cin >> n;
    map <int, int> cost;
    for (int i = 0; i < n; ++i) {
        int a, x;
        cin >> a >> x;
        cost[a] = max(cost[a], x);
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int b, y;
        cin >> b >> y;
        cost[b] = max(cost[b], y);
    }
    ll ans = 0;
    for (auto &p : cost) ans += p.second;
    cout << ans << '\n';
}