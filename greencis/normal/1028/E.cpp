#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
ll a[150000];
ll b[150000];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    ll mx = 0;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], mx = max(mx, a[i]);
    a[0] = a[n];
    a[n + 1] = a[1];
    if (!mx) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i)
            cout << (i ? " 1" : "1");
        cout << "\n";
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        if (a[i - 1] < a[i] && a[i] > 0) {
            b[i] = a[i];
            int cur = i;
            int nxt = (i - 1 + n - 1) % n + 1;
            for (int j = 0; j < n - 1; ++j) {
                ll coeff = (mx + 1 - a[nxt] + b[cur] - 1) / b[cur];
                b[nxt] = coeff * b[cur] + a[nxt];
                cur = (cur - 1 + n - 1) % n + 1;
                nxt = (nxt - 1 + n - 1) % n + 1;
            }
            cout << "YES\n";
            for (int i = 1; i <= n; ++i)
                cout << (i > 1 ? " " : "") << b[i];
            cout << "\n";
            return 0;
        }
    }

    cout << "NO\n";
}