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

int N, M, dp[200009], cnt[200009];
long long maxi;
vector < int > v[200009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
while (M --)
{
    int x, y;
    scanf ("%d %d", &x, &y), cnt[x] ++, cnt[y] ++;
    if (x > y) v[x].push_back (y);
    else v[y].push_back (x);
}
for (int i=1; i<=N; i++)
{
    int maxi2 = 0;
    for (vector < int > :: iterator it = v[i].begin (); it != v[i].end (); it ++)
        if (dp[*it] > maxi2) maxi2 = dp[*it];
    dp[i] = maxi2 + 1;
    if (1LL * dp[i] * cnt[i] > maxi) maxi = 1LL * dp[i] * cnt[i] ;
}
printf ("%I64d\n", maxi);

return 0;
}