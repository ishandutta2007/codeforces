#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int w, n, m;
int a[MAXN];
string f[MAXN];
void read() {
    cin >> w >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> f[i];
    for (int i = 0; i < m; ++i) reverse(f[i].begin(), f[i].end());
}

const int LG = 15;

int get(char c, int t) {
    if (c == 'A') {
        if (t == 0) return 2;
        else return 0; 
    }
    else if (c == 'O') {
        if (t == 0) return 0;
        else return -1;
    }
    else if (c == 'X') {
        if (t == 0) return 0;
        else return 1;
    }
    else if (c == 'a') {
        if (t == 0) return -1;
        else return 1;
    }
    else if (c == 'o') {
        if (t == 0) return 1;
        else return 2;
    }
    else {
        if (t == 0) return 1;
        else return 0;
    }
}

int pr[250][2];
void prec() {
    for (int i = 0; i < 250; ++i) {
        pr[i][0] = get(i, 0);
        pr[i][1] = get(i, 1);
    }   
}

int dp[MAXN][LG];
int cnt[MAXN];

void solve() {
    for (int i = 0; i < n; ++i) ++cnt[a[i]];
    for (int mask = 0; mask < (1 << w); ++mask) {
        dp[mask][LG - 1] = cnt[mask];
        for (int i = LG - 2; i >= 0; --i) {
            if ((mask >> i) & 1) {
                dp[mask][i] = dp[mask][i + 1] + dp[mask ^ (1 << i)][i];
            }
            else {
                dp[mask][i] = dp[mask][i + 1];
            }   
        }
    }
}

const int KEK = 1e6 + 7;

bool mem[KEK];
int res[KEK];

int get(int *want) {
    for (int i = 0; i < w; ++i) if (want[i] == -1) return 0;     

    int hash = 0;
    for (int i = 0; i < w; ++i) hash = hash * 3 + want[i];
    if (mem[hash]) return res[hash];

    int ans = 0;
    int t = 0;
    for (int i = 0; i < w; ++i) t += (want[i] == 1);
    for (int mask = 0; mask < (1 << t); ++mask) {
        int nmask = 0;
        int u = 0;
        int p = 0;
        for (int i = 0; i < w; ++i) {
            if (want[i] == 2) {
                nmask |= (1 << i);
            }
            else if (want[i] == 1) {
                if ((mask >> u) & 1) {
                    nmask |= (1 << i);
                }
                else {
                    ++p;
                }
                ++u;
            }
        }
        if (p % 2 == 0) ans += dp[nmask][0];
        else ans -= dp[nmask][0];
    }

    mem[hash] = 1;
    res[hash] = ans;

    return ans;
}

int want[LG];
void print() {
    for (int i = 0; i < m; ++i) {
        int ans = 0;
        for (int mask = 0; mask < (1 << w); ++mask) {
            for (int j = 0; j < w; ++j) want[j] = pr[(int)f[i][j]][(mask >> j) & 1];
            int add = get(want) * cnt[mask];
            ans += add;
        }
        cout << ans << '\n';
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    prec();
    read();
    solve();
    print();

    return 0;
}