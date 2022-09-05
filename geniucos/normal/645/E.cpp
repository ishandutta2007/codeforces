#include<cstdio>
#include<bitset>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int N, M, K, mod, ap[30], dp[30];
char sir[1000009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &K), mod = 1e9 + 7;
gets (sir + 1), M = strlen (sir + 1);
for (int i=1; i<=M; i++)
    sir[i] -= 'a';
int tot = 1;
for (int i=1; i<=N + M; i++)
{
    int mini = N + M + 1, how = -1;
    if (i <= M) how = sir[i];
    else
    {
        for (int j=0; j<K; j++)
            if (ap[j] < mini) mini = ap[j], how = j;
    }
    int cnt = tot - dp[how];
    if (cnt < 0) cnt += mod;
    tot += cnt;
    if (tot >= mod) tot -= mod;
    dp[how] += cnt;
    if (dp[how] >= mod) dp[how] -= mod;
    ap[how] = i;
}
printf ("%d\n", tot);

return 0;
}