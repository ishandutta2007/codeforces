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
const int N = 5007, MOD = 1000 * 1000 * 1000 + 7;
int n, m, a[N], f[N], h[N];

bool l[N], r[N];
vector <int> pos[N];
int cnt[N][4];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]].app(i);
    }
    int ptr = 0;
    for (int i = 0; i < m; ++i) {
        int ff, hh;
        cin >> ff >> hh;
        if (hh <= pos[ff].size()) {
            f[ptr] = ff;
            h[ptr] = hh;
            ++ptr;
        }   
    }
    m = ptr;

    ii ans = {0, 0};
    for (int i = 0; i <= m; ++i) {
        
        int to;
        if (i == m)
            to = -1;
        else
            to = pos[f[i]][h[i] - 1];

        for (int j = 0; j < m; ++j)
            l[j] = r[j] = 1;
        r[i] = 0;
        for (int j = 0; j < m; ++j) {

            if (i == j)
                continue;

            if (i == m || pos[f[j]][h[j] - 1] >= to)
                l[j] = 0;
            int sz = pos[f[j]].size();
            if (pos[f[j]][sz - h[j]] <= to)
                r[j] = 0;
        }

        /*
        cout << "lr\n";
        for (int j = 0; j < m; ++j)
            cout << l[j] << ' ' << r[j] << '\n';
        */

        for (int j = 0; j < N; ++j) 
            for (int k = 0; k < 4; ++k)
                cnt[j][k] = 0;
        for (int j = 0; j < m; ++j)
            ++cnt[f[j]][l[j] * 2 + r[j]];

        int mx = 0, k = 1;
        for (int j = 0; j < N; ++j) {            

            if (i < m && j == f[i]) {    
                ++mx;
                if (cnt[j][1] || cnt[j][3]) {
                    ++mx;
                    int f = cnt[j][1] + cnt[j][3];
                    k = k * f % MOD;
                }   
                continue;
            }   

            if (cnt[j][1] || cnt[j][2] || cnt[j][3]) {
                ++mx;
                if (!cnt[j][2] && !cnt[j][3])
                    k = k * cnt[j][1] % MOD;
                else if (!cnt[j][1] && !cnt[j][3])
                    k = k * cnt[j][2] % MOD;
                else if (!cnt[j][1] && !cnt[j][2] && cnt[j][3] == 1) 
                    k = k * 2 % MOD;
                else {
                    ++mx;

                    int f = cnt[j][1] * (cnt[j][2] + cnt[j][3]) % MOD;
                    f += cnt[j][3] * (cnt[j][2] + cnt[j][3] - 1);
                    f %= MOD;

                    k = k * f % MOD;
                }   
            }
        }           

        //cout << "i " << i << ' ' << mx << ' ' << k << '\n';

        if (mx > ans.f)
            ans = mp(mx, k);
        else if (mx == ans.f)
            ans.s = (ans.s + k) % MOD;
    }   
    cout << ans.f << ' ' << ans.s << '\n';
}