#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll MOD = 1000000007ll;
int n,dp[5005][5005],sumdp[5005][5005];
char s[5005];

int p[5005],lcp[5005],dist[5005][5005];

int compar(int a, int b) {
    while (1) {
        if (s[a] < s[b]) return 1;
        if (s[a] > s[b]) return 0;
        ++a; ++b;
    }
    return 0;
}

inline int comp(int ai, int bi, int len) {
    int cc = dist[ai][bi];
    if (cc >= len) return 0;
    ai += cc;
    bi += cc;
    if (s[ai] < s[bi]) return -1;
    if (s[ai] > s[bi]) return 1;
    return 0;
}

int f(int x, int len) {
    if (x == 0) return 1;
    if (len > x) return 0;
    if (!dp[x][len]) {
        if (x == len)
            dp[x][len] = 1;
        else if (s[x - len + 1] == '0')
            dp[x][len] = 0;
        else {
            dp[x][len] = sumdp[x - len][min(len - 1, x - len)];
            if (x - len - len >= 0) {
                if (comp(x - len - len + 1, x - len + 1, len) < 0)
                    (dp[x][len] += f(x - len, len)) %= MOD;
            }
        }
        sumdp[x][len] = (dp[x][len] + sumdp[x][len-1]) % MOD;
        ++dp[x][len];
    }
    return dp[x][len] - 1;
}

int main()
{
    cin >> n >> s + 1;
    for (int i = 0; i < 5005; ++i) sumdp[0][i] = dp[0][i] = 1;
    for (int i = 0; i < n; ++i)
        p[i] = i + 1;
    sort(p, p + n, compar);
    for (int i = 0; i < n-1; ++i) {
        int cur = 0;
        int ai = p[i], bi = p[i+1];
        while (s[ai] == s[bi]) {
            ++ai; ++bi; ++cur;
        }
        lcp[i] = cur;
        for (int j = i; j >= 0; --j) {
            cur = min(cur, lcp[j]);
            dist[p[i+1]][p[j]] = dist[p[j]][p[i+1]] = cur;
        }
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            f(i, j);
    int ans = 0;
    /*for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j)
            cerr << f(i, j) << " ";
        cerr << endl;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j)
            cerr << dist[i][j] << " ";
        cerr << endl;
    }*/
    for (int i = 1; i <= n; ++i)
        (ans += f(n, i)) %= MOD;
    cout << ans;

    return 0;
}