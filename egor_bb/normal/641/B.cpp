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

const int MAXN = 117;

int n, m, q, t, val[MAXN][MAXN], ans[MAXN][MAXN], x, y, z;
pair<int, int> pos[MAXN][MAXN];

int main()
{
#ifdef lordf
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif

    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            pos[i][j] = mp(i, j);
    while (q--)
    {
        scanf("%d", &t);
        if (t == 1)
        {
            scanf("%d", &x);
            x--;
            pos[x][m] = pos[x][0], val[x][m] = val[x][0];
            for (int i = 0; i < m; i++)
                pos[x][i] = pos[x][i + 1], val[x][i] = val[x][i + 1];
        }
        else if (t == 2)
        {
            scanf("%d", &y);
            y--;
            pos[n][y] = pos[0][y], val[n][y] = val[0][y];
            for (int i = 0; i < n; i++)
                pos[i][y] = pos[i + 1][y], val[i][y] = val[i + 1][y];
        }
        else
        {
            scanf("%d %d %d", &x, &y, &z);
            x--, y--;
            val[x][y] = z;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans[pos[i][j].first][pos[i][j].second] = val[i][j]; 
    for (int i = 0; i < n; i++, putchar('\n'))
        for (int j = 0; j < m; j++)
            printf("%d ", ans[i][j]);

    return 0;
}