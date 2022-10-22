#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 5007, LG = 15, MOD = 1000 * 1000 * 1000 + 7, BASE = 129;
bool is[N][N], to[N][N];
int lcp[N][N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    string s;
    cin >> s;
    int n = s.size();

    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (s[i] == s[j])
                lcp[i][j] = lcp[i + 1][j + 1] + 1;
            else
                lcp[i][j] = 0;
        }
    }   

    for (int l = n - 1; l >= 0; --l) {
        for (int r = l; r < n; ++r) {
            if (l == r) {
                is[l][r] = 1;
            }   
            else if (l + 1 == r) {
                is[l][r] = s[l] == s[r];
            }   
            else {
                is[l][r] = s[l] == s[r] && is[l + 1][r - 1];
            }   
        }   
    }   

    for (int t = 1; t < LG && t <= s.size(); ++t) {
        int ans = 0;
        for (int l = 0; l < n; ++l)
            for (int r = l; r < n; ++r)
                ans += is[l][r];

        cout << ans << ' ';

        memset(to, 0, sizeof to);
        for (int l = 0; l < n; ++l) {
            for (int r = l + 1; r < n; ++r) {
                int len = r - l + 1;
                int m = len >> 1;
                to[l][r] = is[l][l + m - 1] && is[r - m + 1][r] && lcp[l][r - m + 1] >= m;
            }
        }                   

        for (int l = 0; l < n; ++l)
            for (int r = 0; r < n; ++r)
                is[l][r] = to[l][r];
    }   
    for (int t = LG; t <= s.size(); ++t)
        cout << 0 << ' ';
    cout << endl;
}