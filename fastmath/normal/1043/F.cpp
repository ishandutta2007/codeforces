#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")

#include <bits/stdc++.h>

using namespace std;

#define int long long 

const int MAXN = 3e5 + 7;

bool pr[MAXN];
vector <int> d[MAXN];
void prec() {
    for (int i = 2; i < MAXN; ++i) pr[i] = 1;
    for (int i = 2; i < MAXN; ++i) {
        if (pr[i]) {
            for (int j = i * 2; j < MAXN; j += i) pr[j] = 0;
            for (int j = i; j < MAXN; j += i) d[j].push_back(i);
        }
    }
}   

int n;
int a[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
}

int vpr[MAXN], cnt[MAXN];
bool have[MAXN];
int dp[MAXN];
void solve() {
    for (int i = 0; i < n; ++i) have[a[i]] = 1;

    int t = 0;                                                                
    for (int i = 0; i < n; ++i) t = __gcd(t, a[i]);
    if (t != 1) {
        cout << "-1\n";
        exit(0);
    }   
        
    for (int i = 0; i < n; ++i) {
        vector <int> v = d[a[i]];

        int sz = d[a[i]].size();
        for (int mask = 0; mask < (1 << sz); ++mask) {
            int f = 1;
            for (int t = 0; t < sz; ++t) if ((mask >> t) & 1) f *= d[a[i]][t];
            if (__builtin_popcount(mask) % 2 == 0) cnt[f]++;
            else cnt[f]--;
        }   
    }

    for (int i = 1; i < MAXN; ++i) {
        for (int j = i; j < MAXN; j += i) {
            vpr[j] += cnt[i];
        }
    }

    const int INF = 1e9 + 7;

    dp[1] = 0;
    for (int i = 2; i < MAXN; ++i) {
        vector <int> v;
        for (int d = 1; d * d <= i; ++d) {
            if (i % d == 0) {
                v.push_back(d);
                v.push_back(i / d);
            }
        }   

        dp[i] = INF;
        for (int d : v) {
            if (vpr[d]) {
                dp[i] = min(dp[i], dp[i / d] + 1);
            }   
        }
    }   
}

void print() {
    int ans = MAXN;
    for (int i = 1; i < MAXN; ++i) {
        if (have[i]) ans = min(ans, dp[i] + 1);
    }
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