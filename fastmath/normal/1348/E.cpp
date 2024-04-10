#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 507;
bool dp1[N][N], dp2[N][N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n, k;
    cin >> n >> k;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }   

    int sa = 0, sb = 0;
    for (int i = 0; i < n; ++i) {
        sa += a[i];
        sb += b[i];
    }   

    dp1[0][0] = 1;
    int cur = 0;

    for (int i = 0; i < n; ++i) {
        memset(dp2, 0, sizeof dp2);
        for (int x = 0; x <= a[i] && x < k; ++x) {
            int y = (a[i] + b[i] - x) % k;
            if (y <= b[i]) {
                for (int i = 0; i < k; ++i) {
                    int j = cur - i;
                    if (j < 0)
                        j += k;
                    if (dp1[i][j]) {
                        int i1 = i + x;
                        if (i1 >= k)
                            i1 -= k;
                        int j1 = j + y;
                        if (j1 >= k)
                            j1 -= k;
                        dp2[i1][j1] = 1;
                    }   
                }   
            }
        }           
        for (int x = 0; x < k; ++x)
            for (int y = 0; y < k; ++y)
                dp1[x][y] = dp2[x][y];
        cur += a[i] + b[i];
        cur %= k;
    }   

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (dp1[i][j] && i + j <= (sa + sb) % k) {
                cout << (sa + sb) / k << endl;
                exit(0);
            }   
        }   
    }   

    cout << (sa / k) + (sb / k) << endl;
}