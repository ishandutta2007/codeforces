#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) {
        ll n, m, k;
        cin >> n >> m >> k;
        if (max(n, m) > k) { cout << "-1\n"; continue; }
        ll add = min(n, m);
        k -= add;
        n -= add;
        m -= add;
        if (m < n)
            swap(m, n);
        ll add2 = m / 2 * 2;
        m -= add2;
        k -= add2;
        ll ans = add + add2 + k;
        if (m == 0) {
            if (k % 2)
                ans -= 2;
        } else {
            --ans;
        }
        cout << ans << "\n";
    }
}