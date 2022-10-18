#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

int n, m;
int u[4005][9];

int main()
{
    cin >> n >> m;
    bool window = true;
    for (int i = 0; i < m; ++i) {
        if (window) {
            if (i % 2 == 0) u[i / 2][0] = i + 1;
            else u[i / 2][3] = i + 1;
            if (i + 1 == n + n) window = false;
        } else {
            if (i % 2 == 0) u[i / 2 - n][1] = i + 1;
            else u[i / 2 - n][2] = i + 1;
        }
    }

    for (int i = 0; i < 4005; ++i) {
        if (u[i][1]) cout << u[i][1] << " ";
        if (u[i][0]) cout << u[i][0] << " ";
        if (u[i][2]) cout << u[i][2] << " ";
        if (u[i][3]) cout << u[i][3] << " ";
    }

    return 0;
}