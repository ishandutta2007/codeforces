#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[200105], s;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> s;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    ll ans = 0;
    if (a[n / 2] == s) ans = 0;
    else if (a[n / 2] > s) {
        for (int i = n / 2; i >= 0 && a[i] > s; --i)
            ans += a[i] - s;
    } else {
        for (int i = n / 2; i < n && a[i] < s; ++i)
            ans += s - a[i];
    }
    cout << ans << endl;
}