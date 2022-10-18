#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m;
ll a[300105], b[300105];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    ll xa = 0, xb = 0;
    for (int i = 0; i < n; ++i) cin >> a[i], xa ^= a[i];
    for (int i = 0; i < m; ++i) cin >> b[i], xb ^= b[i];
    if (xa != xb) { cout << "NO"; }
    else {
        cout << "YES\n";
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m - 1; ++j)
                cout << "0 ";
            cout << a[i] << "\n";
        }
        for (int j = 0; j < m - 1; ++j)
            cout << b[j] << " ", a[n - 1] ^= b[j];
        cout << a[n - 1] << "\n";
    }
}