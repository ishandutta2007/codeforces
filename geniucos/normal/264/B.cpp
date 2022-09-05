#include<cstdio>
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

int N, dp[100009];

vector < int > v[100009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);

for (int i=2; i<=100000; i++)
    for (int j=i; j<=100000; j+=i)
        v[j].push_back (i);

int ans = 0;
for (int i=1; i<=N; i++)
{
    int maxi = 0, ai;
    scanf ("%d", &ai);
    for (vector < int > :: iterator it = v[ai].begin (); it != v[ai].end (); it ++)
        if (dp[*it] > maxi)
            maxi = dp[*it];
    maxi ++;
    if (maxi > ans)
        ans = maxi;
    for (vector < int > :: iterator it = v[ai].begin (); it != v[ai].end (); it ++)
        dp[*it] = maxi;
}
printf ("%d\n", ans);

return 0;
}