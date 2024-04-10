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

int n, a;

int main()
{
#ifdef lordf
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif

    scanf("%d %d", &n, &a);
    printf("%d\n", (a % 2 == 0) ? (1 + (n - a) / 2) : (a / 2 + 1));

    return 0;
}