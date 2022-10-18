#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a[1005][1005],u[1005];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    }
    for (int i = 0; i < n; ++i) u[i] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == i) continue;
            if (a[i][j] & 1) u[i] = 0;
            if (a[i][j] & 2) u[j] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) ans += u[i];
    cout << ans << endl;
    for (int i = 0; i < n; ++i)
        if (u[i]) cout << i+1 << " ";

    return 0;
}