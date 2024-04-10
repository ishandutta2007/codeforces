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

int N;
long long ans;
pair < int, int > a[200009];

long long comb2 (int N)
{
    return (long long) (1LL * N * (N - 1)) / 2LL;
}

void solve ()
{
    sort (a + 1, a + N + 1);
    for (int i=1; i<=N; i++)
    {
        int j;
        for (j=i; j<=N; j++)
            if (a[j].first != a[i].first) break;
        j --;
        ans += comb2 (j - i + 1);
        i = j;
    }
}

void diffeq ()
{
    for (int i=1; i<=N; i++)
    {
        int j;
        for (j=i; j<=N; j++)
            if (a[j] != a[i]) break;
        j --;
        ans -= comb2 (j - i + 1);
        i = j;
    }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d %d", &a[i].first, &a[i].second);
solve ();
for (int i=1; i<=N; i++)
    swap (a[i].first, a[i].second);
solve ();
diffeq ();
printf ("%I64d\n", ans);
return 0;
}