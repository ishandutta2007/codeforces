#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

int n, a[100105];
ll sum;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i], sum += a[i];
    for (int iter = 2; iter--; ) {
        ll cur = 0;
        set<ll> s;
        for (int i = 0; i < n; ++i) {
            s.insert(a[i]);
            cur += a[i];
            if (cur * 2 == sum) {
                cout << "YES\n";
                return 0;
            }
            /// cur - x == sum - cur + x
            /// 2 * cur - sum = 2x
            if (sum % 2 == 0 && s.find((2 * cur - sum) / 2) != s.end()) {
                cout << "YES\n";
                return 0;
            }
        }
        reverse(a, a + n);
    }
    cout << "NO\n";

    return 0;
}