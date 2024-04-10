#include <bits/stdc++.h>

using namespace std;

#define int long long

mt19937 rnd(time(0));

const int MAXN = 1e5 + 7;
const int MAXM = 11;

const int MN = 1e9;
const int ADD = 1e6 + 7;

int n, m;
int a[MAXM][MAXN];

void read() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) cin >> a[i][j];
    }   
}

bool prime(int n) {
    for (int d = 2; d * d <= n; ++d) {
        if (n % d == 0) return 0;
    }   
    return 1;
}

int MOD = -1;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

int pw[MAXN];

void prec() {
    while (1) {
        MOD = MN + rnd() % ADD;
        if (prime(MOD)) break;
    }   
    pw[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        pw[i] = mod(pw[i - 1] * MAXN);
    }
}   

int ans = 0;

int h[MAXM][MAXN];
int pos[MAXM][MAXN];

int geth(int i, int p, int len) {
    return mod(h[i][p + len] - h[i][p] * pw[len]);
}   

void solve() {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) h[i][j + 1] = mod(h[i][j] * MAXN + a[i][j]);
    }   

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            pos[i][a[i][j]] = j;
        }   
    }

    for (int i = 0; i < n; ++i) {
        int l = 1;
        int r = MAXN;
        for (int j = 0; j < m; ++j) {
            r = min(r, n - pos[j][i + 1] + 1);
        }   
        while (l < r - 1) {
            int mid = (l + r) / 2;
            bool ch = 1;
            int want = geth(0, pos[0][i + 1], mid);
            for (int j = 1; j < m; ++j) {
                ch &= (geth(j, pos[j][i + 1], mid) == want);
            }   
            if (ch) l = mid;
            else r = mid;
        }
        ans += l;
    }   
}   

void print() {
    cout << ans << '\n';
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