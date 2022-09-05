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

int N, cnt[30009], a[5009];
long long tot, dp[30009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
sort (a + 1, a + N + 1);
for (int i=1; i<=N; i++)
    for (int j=i+1; j<=N; j++)
        cnt[a[j] - a[i]] ++;
int v = a[N] - a[1];
for (int i=0; i<=v; i++)
    for (int j=0; j<=v; j++)
        dp[i + j] += 1LL * cnt[i] * cnt[j];
for (int i=0; i<=2 * v; i++)
    for (int k=i + 1; k<=v; k++)
        tot += 1LL * dp[i] * cnt[k];
long long mut = N * (N - 1) / 2;
mut = 1LL * mut * mut * mut;
printf ("%.10f\n", (double) tot / mut);
return 0;
}