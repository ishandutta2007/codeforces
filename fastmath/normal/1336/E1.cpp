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
const int LG = 36, MOD = 998244353, K = 15;
void add(int &a, int b) { a += b; if (a >= MOD) a -= MOD; }
int a[LG], ans[LG];
int dp1[LG][1 << K], dp2[LG][1 << K];
void solve(int m) {
    vector <int> big;
    for (int i = K; i < m; ++i)
        if (a[i])
            big.app(a[i]);
    for (int mask = 0; mask < (1 << big.size()); ++mask) {
        int sum = 0;
        for (int i = 0; i < big.size(); ++i)
            if ((mask >> i) & 1)
                sum ^= big[i];                        
        int r = 0;
        for (int i = K; i < m; ++i)
            if ((sum >> i) & 1)
                ++r;
        ++dp1[r][sum & ((1 << K) - 1)];                
    }   
    for (int b = K - 1; b >= 0; --b) {
        for (int i = 0; i < LG; ++i)
            for (int j = 0; j < (1 << K); ++j)
                dp2[i][j] = 0;

        for (int i = 0; i < LG; ++i) 
            for (int j = 0; j < (1 << K); ++j) {

                {
                    int to = j;
                    if ((to >> b) & 1)
                        add(dp2[i + 1][to - (1 << b)], dp1[i][j]);
                    else
                        add(dp2[i][to], dp1[i][j]);
                }

                if (a[b]) {
                    int to = j ^ a[b];
                    if ((to >> b) & 1)
                        add(dp2[i + 1][to - (1 << b)], dp1[i][j]);
                    else
                        add(dp2[i][to], dp1[i][j]);
                }

            }   

        for (int i = 0; i < LG; ++i)
            for (int j = 0; j < (1 << K); ++j)
                dp1[i][j] = dp2[i][j];
    }   
    for (int i = 0; i <= m; ++i)
        ans[i] = dp1[i][0];
}
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    int sh = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        bool add = 0;
        for (int j = m - 1; j >= 0; --j) {
            if ((x >> j) & 1) {
                if (!a[j]) {
                    add = 1;
                    a[j] = x;
                    break;
                }
                else {
                    x ^= a[j];
                }   
            }   
        }   
        sh += !add;
    }   
    solve(m);
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j < sh; ++j)
            ans[i] = (ans[i] << 1) % MOD;
        cout << ans[i] << ' ';
    }   
    cout << endl;
}