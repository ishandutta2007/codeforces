#include <bits/stdc++.h>

using namespace std;

const int MAXN = 107;

char a[4][MAXN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 4; ++i) for (int j = 0; j < MAXN; ++j) a[i][j] = '.';

    int n, k;
    cin >> n >> k;

    if (k % 2) {
        int p = n / 2;
        a[1][p] = '#';
        --k;
        int r = 1;
        while (k && r < p) {
            a[1][p - r] = a[1][p + r] = '#';        
            k -= 2;
            ++r;
        }
        r = 1;
        while (k) {
            a[2][p - r] = a[2][p + r] = '#';
            k -= 2;
            ++r;
        }
    }
    else {
        for (int i = 0; i < (k / 2); ++i) {
            a[1][i + 1] = '#';
            a[2][i + 1] = '#';
        }        
    }

    cout << "YES\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) cout << a[i][j];
        cout << '\n';
    }

    return 0;
}