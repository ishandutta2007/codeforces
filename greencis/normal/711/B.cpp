#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
ll a[505][505];
int nx, ny;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (!a[i][j]) nx = j, ny = i;
        }
    }

    if (n == 1) {
        cout << 1;
        return 0;
    }

    int row = ny ? 0 : 1;
    ll cur1 = 0;
    ll cur2 = 0;
    for (int i = 0; i < n; ++i)
        cur1 += a[row][i], cur2 += a[ny][i];

    ll x = cur1 - cur2;
    if (x <= 0) { cout << -1; return 0; }
    a[ny][nx] = x;

    for (int i = 0; i < n; ++i) {
        ll cur3 = 0;
        for (int j = 0; j < n; ++j) {
            cur3 += a[i][j];
        }
        if (cur1 != cur3)  { cout << -1; return 0; }
        cur3 = 0;
        for (int j = 0; j < n; ++j) {
            cur3 += a[j][i];
        }
        if (cur1 != cur3)  { cout << -1; return 0; }
    }

    ll diag1 = 0;
    ll diag2 = 0;
    for (int i = 0; i < n; ++i)
        diag1 += a[i][i], diag2 += a[n - 1 - i][i];
    if (diag1 == cur1 && diag2 == cur1) {
        cout << x;
    } else cout << -1;

    return 0;
}