#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[100105], b[100105];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; ++i) { cin >> a[i]; ans += a[i]; }
    for (int i = 0; i < n; ++i) { cin >> b[i]; ans -= b[i]; }
    sort(a, a + n);
    sort(b, b + n);
    int ai = n - 1, bi = n - 1;
    for (int i = 0; i < n; ++i) {
        if (ai >= 0 && (bi < 0 || a[ai] > b[bi]))
            ans += a[ai--];
        else
            ans += b[bi--];

        if (ai >= 0 && (bi < 0 || a[ai] > b[bi]))
            ans -= a[ai--];
        else
            ans -= b[bi--];
    }
    cout << ans / 2 << endl;
}