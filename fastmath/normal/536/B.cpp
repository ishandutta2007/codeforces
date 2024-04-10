#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;
const int C = 26;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

int HMOD = -1;

bool prime(int n) {
    for (int d = 2; d * d <= n; ++d) {
        if (n % d == 0) return 0;
    }   
    return 1;
}

const int BASE = 129;
const int MN = 1000 * 1000 * 1000;
const int ADD = 1e6 + 7;

mt19937 rnd(time(0));

void gen() {
    while (1) {
        HMOD = MN + rnd() % ADD;
        if (prime(HMOD)) {
            break;
        }   
    }   
}

int hmod(int n) {
    return (n % HMOD + HMOD) % HMOD;
}

string t;

int h[MAXN];
int pw[MAXN];
void calc() {
    for (int i = 0; i < (int)t.size(); ++i) h[i + 1] = hmod(h[i] * BASE + t[i]);
    pw[0] = 1;
    for (int i = 1; i < MAXN; ++i) pw[i] = hmod(pw[i - 1] * BASE);
}

int geth(int l, int r) {
    return hmod(h[r + 1] - h[l] * pw[r - l + 1]);
}   

bool check(int i, int j) {
    if (i + t.size() - 1 < j) return 1;
    int p = j - i;
    int len = t.size() - p;
    return geth(p, t.size() - 1) == geth(0, len - 1);
}   

int add[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    cin >> t;

    vector <int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        --a[i];
    }

    gen();
    calc();

    for (int i = 0; i < m - 1; ++i) {
        if (!check(a[i], a[i + 1])) {
            cout << "0\n";
            exit(0);
        }   
    }   
    
    for (int i = 0; i < m; ++i) {
        ++add[a[i]];
        --add[a[i] + t.size()];
    }   

    int ans = 1;
    int curr = 0;
    for (int i = 0; i < n; ++i) {
        curr += add[i];
        if (!curr) ans = mod(ans * C);
    }   

    cout << ans << '\n';
    return 0;
}