#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,a,cnt[105];

int main()
{
    cin >> n >> m;
    int ans = -1, ansi = 2e9;
    for (int i = 0; i < m; ++i) {
        int mx = -1, mxi = -1;
        for (int j = 0; j < n; ++j) {
            cin >> a;
            if (a > mx) mx = a, mxi = j;
        }
        ++cnt[mxi];
        if (cnt[mxi] > ans || cnt[mxi] == ans && mxi < ansi) ans = cnt[mxi], ansi = mxi;
    }
    cout << ansi + 1;


    return 0;
}