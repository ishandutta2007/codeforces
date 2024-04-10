#include <bits/stdc++.h>

#define MOD (1000000007)
#define EPS (1e-9)
#define INF (2117117117)
#define LLINF (2117117117117117117LL)
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define sqr(a) ((a) * (a))
#define sz(a) ((int) (a).size())
const double PI = acos(-1.0);

typedef unsigned int uint;
typedef long long llong;
typedef long double ldouble;
typedef unsigned long long ullong;

#define TASK "task"

using namespace std;

const int MAXN = 200117, MAXM = 1200117, C = 5, MAXX = 1000000120;

int n, k, a[MAXN], b, c, m, p[MAXM];
llong ans, s[C];
priority_queue<llong> q[C];

inline void add(int x)
{
    int rx = ((x % C) + C) % C;
    for (int i = 0; i < C; i++)
    {
        int d = c * ((i < rx) ? (C + i - rx) : (i - rx));
        llong xx = d + 1LL * b * (((MAXX + i) - (x + ((i < rx) ? (C + i - rx) : (i - rx)))) / C);
        if (sz(q[i]) < k)
            s[i] += xx, q[i].push(xx);
        else if (q[i].top() > xx)
            s[i] -= q[i].top() - xx, q[i].pop(), q[i].push(xx);
    }
}

int main()
{
#ifdef lordf
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    
    scanf("%d %d %d %d", &n, &k, &b, &c);
    b = min(b, 5 * c);
    for (int i = 0; i < n; scanf("%d", &a[i++]));
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= 5; j++)
            p[m++] = a[i] + j;
    sort(p, p + m);
    m = unique(p, p + m) - p;
    sort(a, a + n);

    ans = LLINF;
    for (int i = 0, j = 0; i < m; i++)
    {
        for (; j < n && p[i] >= a[j]; add(a[j++]));
        int t = ((p[i] % C) + C) % C;
        if (sz(q[t]) == k)
            ans = min(ans, s[t] - 1LL * k * b * (((MAXX + t) - p[i]) / C));
    }
    printf("%lld\n", ans);

    return 0;
}