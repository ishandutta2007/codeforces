#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,a[99][99],p[99],u[99];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int w = n; w >= 1; --w) {
        int mx = -1, mxi = -1;
        for (int i = 0; i < n; ++i) {
            if (u[i]) continue;
            int cur = 0;
            for (int j = 0; j < n; ++j)
                cur = max(cur, a[i][j]);
            if (cur > mx)
                mx = cur, mxi = i;
        }
        p[mxi] = w;
        u[mxi] = 1;
    }
    for (int i = 0; i < n; ++i)
        cout << p[i] << " ";

    return 0;
}