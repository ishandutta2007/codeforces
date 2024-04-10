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

const int MAXN = 150117;

int n, k, q, a[MAXN], tp, id, b[66];

int main()
{
#ifdef lordf
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif

    scanf("%d %d %d", &n, &k, &q);
    for (int i = 0; i < n; scanf("%d", &a[i++]));
    while (q--)
    {
        scanf("%d %d", &tp, &id);
        id--;
        if (tp == 1)
        {
            b[min(n, k)] = a[id];
            sort(b, b + min(n, k) + 1);
            reverse(b, b + min(n, k) + 1);
        }
        else
            printf((find(b, b + min(n, k), a[id]) == (b + min(n, k))) ? "NO\n" : "YES\n");
    }

    return 0;
}