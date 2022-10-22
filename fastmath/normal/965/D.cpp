#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
#define int long long

const int MAXN = 1e5 + 7;
const int INF = 1e16 + 7;

int a[MAXN], pref[MAXN];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, l;
    cin >> n >> l;
    --n;

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
    
    int ans = INF;
    for (int i = 0; i + l - 1 < n; ++i) {
        ans = min(ans, pref[i + l] - pref[i]);
    }

    cout << ans << '\n';
    return 0;
}