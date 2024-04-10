#include <bits/stdc++.h>
 
using namespace std;
 
const bool HOME = 0;

const int MAXN = 5e5 + 7;
const int MAXV = 1e7 + 1e6;
const int MOD = 1000 * 1000 * 1000 + 7;
const int K = 3200;
  
inline int mod(long long n) {
    n %= MOD;
    if (n < 0) return n + MOD;
    else return n;
}
 
long long pw[MAXN];
bool pr[MAXV];
int mx[MAXV];

void precalc() {
    pw[0] = 1;
    for (int i = 1; i < MAXN; ++i) pw[i] = mod(pw[i - 1] << 1);
    for (int i = 2; i < MAXV; ++i) pr[i] = 1;
    for (int i = 2; i < MAXV; ++i) {
        if (pr[i]) {
            for (int j = 2 * i; j < MAXV; j += i) {
                pr[j] = 0;
                mx[j] = max(mx[j], i);
            }
        }
    }
}
 
int n;
int a[MAXN];
int cnt[MAXV];
 
void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
}
 
vector <int> d[K];

int fact[1 << 10];
 
int getpr(int x) {
    int num = x % K;
   
    if (d[num].empty()) d[num].push_back(x);
    else if (d[num].back() < mx[x]) d[num].push_back(mx[x]);

    fact[0] = 1;
    int ans = cnt[1];
    for (int mask = 1; mask < (1 << (int)d[num].size()); ++mask) {
        int p = __builtin_clz(mask) ^ 31;
        fact[mask] = d[num][p] * fact[mask ^ (1 << p)];
        if (__builtin_popcount(mask) & 1) ans -= cnt[fact[mask]];
        else ans += cnt[fact[mask]];
    }
 
    return ans;
}
  
double gett() {
    return (double)clock() / CLOCKS_PER_SEC;
}

int acnt[MAXV];
int ans = 0;
long long dp[MAXV];
void solve() {
    double tmp;

    if (HOME) tmp = gett();
    for (int i = 0; i < n; ++i) ++acnt[a[i]];
    for (int i = 1; i < MAXV; ++i) {
        for (int j = i; j < MAXV; j += i) {
            cnt[i] += acnt[j];
        }
    }
    if (HOME) cerr << gett() - tmp << '\n';
 
    if (HOME) tmp = gett();
    for (int i = K - 1; i >= 0; --i) {
        for (int j = 0; j < K; ++j) {
            d[j].clear();
        }
           
        for (int t = 2; t < K; ++t) {
            if (!pr[t]) continue;
            int tl = (i * K - 1) / t + 1;
            int tr = (i * K + K - 1) / t;
            for (int j = tl; j <= tr; ++j) {
                d[(t * j) % K].push_back(t);
            }
        }
 
        for (int j = K - 1; j >= 0; --j) {
            int t = i * K + j;
            if (t == 1) break;
 
            dp[t] = mod(pw[cnt[t]] - 1);
            for (int k = 2 * t; k < MAXV; k += t) {
                dp[t] -= dp[k];
            }
            dp[t] = mod(dp[t]);
 
            ans += mod(dp[t] * getpr(t));
            ans = mod(ans);
        }  
    }

    if (HOME) cerr << gett() - tmp << '\n';
}
 
void print() {
    printf("%d\n", ans);
}
 
signed main() {
    if (HOME) freopen("input.txt", "r", stdin);
    if (HOME) freopen("output.txt", "w", stdout);
 
    precalc();
    if (HOME) cerr << gett() << '\n';
    read();
    solve();
    print();
 
    if (HOME) cerr << gett() << '\n';
    return 0;
}