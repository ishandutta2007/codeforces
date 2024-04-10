#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);

    int n, k, x, cur = 0;
    cin >> n >> k;
    ll ans = 0;
    map<int, int> mp; /// stupid multiset, never ever use it again
    for (int i = 1; i <= n; ++i) {
        ++mp[cur];
        cin >> x;
        cur ^= x;
        if (mp[cur] > mp[cur ^ ((1 << k) - 1)])
            cur ^= ((1 << k) - 1);
        ans += i - mp[cur];
    }
    cout << ans << endl;
}