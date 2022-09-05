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

int diff, nr, N, aib[400009], su[200009], di[200009], dp[200009];
pair < int , int > b[400009], a[200009];

void U (int poz, int val)
{
    while (poz <= diff)
    {
        if (val > aib[poz])
            aib[poz] = val;
        poz += poz - (poz & (poz - 1));
    }
}

int Q (int poz)
{
    int sol = 0;
    while (poz)
    {
        if (aib[poz] > sol)
            sol = aib[poz];
        poz &= poz - 1;
    }
    return sol;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d %d", &a[i].first, &a[i].second);
sort (a + 1, a + N + 1);

for (int i=1; i<=N; i++)
{
    nr ++;
    b[nr].first = a[i].first + a[i].second;
    b[nr].second = i;

    nr ++;
    b[nr].first = a[i].first - a[i].second;
    b[nr].second = -i;
}
sort (b + 1, b + nr + 1);

b[0].first = b[1].first - 1;
diff = 0;
for (int i=1; i<=nr; i++)
{
    if (b[i].first != b[i-1].first)
        diff ++;
    if (b[i].second > 0)
        su[b[i].second] = diff;
    else
        di[-b[i].second] = diff;
}

int maxi = 0;
for (int i=1; i<=N; i++)
{
    dp[i] = Q (di[i]) + 1;
    U (su[i], dp[i]);
    if (dp[i] > maxi)
        maxi = dp[i];
}
printf ("%d\n", maxi);

return 0;
}