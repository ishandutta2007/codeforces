#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

int n;
int a[MAXN];
int ans[MAXN];

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    n >>= 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   

    int l = 0;
    int r = a[0];
    ans[n * 2 - 1] = a[0];
    for (int i = 1; i < n; ++i) {
        //x + y = a[i]
        //l <= x <= y <= r

        int tl = -1;
        int tr = r + 1;
        while (tl < tr - 1) {
            int m = (tl + tr) >> 1;
            int x = a[i] - m;
            if (l <= x) {
                tl = m;
            }   
            else {
                tr = m;
            }   
        }   

        r = ans[n * 2 - 1 - i] = tl;
        l = ans[i] = a[i] - tl;
    }   

    for (int i = 0; i < (n << 1); ++i) {
        cout << ans[i] << ' ';
    }   
    cout << '\n';

    return 0;
}