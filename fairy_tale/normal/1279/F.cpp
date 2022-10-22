#include<bits/stdc++.h>
#define fi first
#define se second
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL, int> P;

const int maxn = 1e6 + 5;
const int mod = 998244353;

char s[maxn];
int d[maxn];
P f[maxn];

void check(int n, int l, int c) {
    for(int i = 1; i <= n; ++i) {
        f[i] = f[i - 1];
        int pre = max(i - l, 0);
        int w = f[pre].fi + d[i] - d[pre] - c;
        if(w > f[i].fi || (w == f[i].fi && f[pre].se + 1 < f[i].se))
            f[i] = P(w, f[pre].se + 1);
    }
}

int solve(int n, int k, int l) {
    int L = 0, R = l;
    while(L < R) {
        int mid = (L + R) >> 1;
        check(n, l, mid);
        if(f[n].se > k)
            L = mid + 1;
        else
            R = mid;
    }
    check(n, l, L);
    return d[n] - (f[n].fi + k * L);
}

int main() {
#ifdef FEIFEI
    freopen("E:\\ACM\\test.txt", "r", stdin);
#endif
    int n, k, l;
    scanf("%d%d%d", &n, &k, &l);
    scanf(" %s", s + 1);
    for(int i = 1; i <= n; ++i) {
        d[i] = d[i - 1];
        if(s[i] >= 'A' &&s[i] <= 'Z')
            d[i]++;
    }
    int res = solve(n, k, l);
    for(int i = 1; i <= n; ++i)
        d[i] = i - d[i];
    cout << min(res, solve(n, k, l)) << endl;
    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}