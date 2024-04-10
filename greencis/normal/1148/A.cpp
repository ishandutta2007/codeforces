#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);

    ll a, b, ab;
    cin >> a >> b >> ab;
    /// starts with abababab...
    ll ans = min(a, b) * 2 + ab * 2;
    if (a > b) ++ans;
    /// starts with bababa...
    if (b > 0) {
        ll cur = 1 + min(a, b - 1) * 2 + ab * 2;
        if (a > b - 1)
            ++cur;
        ans = max(ans, cur);
    }
    cout << ans << endl;
}