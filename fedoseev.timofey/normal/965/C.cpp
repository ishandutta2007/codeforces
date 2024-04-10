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
    ll n, k, m, d;
    cin >> n >> k >> m >> d;
    ll ans = 0;
    for (int i = 1; i <= d && (i - 1) * k + 1 <= n; ++i) {
        ll cnt = (i - 1) * k + 1;
        ll num = n / cnt;
        if (num > m) num = m;
        ans = max(ans, num * i);
    }
    cout << ans << '\n';
}