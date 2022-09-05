#include<bits/stdc++.h>

using namespace std;

int cnt, N, a[100], ap[1000];
int dp[] = {0,
1,
1,
2,
2,
2,
3,
3,
3,
3,
4,
4,
4,
4,
4,
5,
5,
5,
5,
5,
5,
6,
6,
6,
6,
6,
6,
6,
7,
7,
7,
7,
7,
7,
7,
7,
8,
8,
8,
8,
8,
8,
8,
8,
8,
9,
9,
9,
9,
9,
9,
9,
9,
9,
9,
10,
10,
10,
10,
10,
10};
/*, dp[65][102000];
long long msk[102000];
map < long long, int > mp;

void back (int pos, int sum, long long curr)
{
    msk[++cnt] = curr, mp[curr] = cnt;
    for (int i=a[pos - 1] + 1; i + sum <= N; i++)
        a[pos] = i, back (pos + 1, sum + i, curr | (1LL << i));
}*/

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
int xo = 0;
for (int i=1; i<=N; i++)
{
    int x;
    scanf ("%d", &x), xo ^= dp[x];
}
if (xo == 0) printf ("YES\n");
else printf ("NO\n");
/*back (1, 0, 0);
for (int i=1; i<=N; i++)
    for (int j=1; j<=cnt; j++)
    {
        vector < int > v;
        for (int k=1; k<=i; k++)
            if ((msk[j] & (1LL << k)) == 0)
            {
                int newJ = mp[msk[j] | (1LL << k)];
                ap[dp[i - k][newJ]] = 1;
                v.push_back (dp[i - k][newJ]);
            }
        bool ok = 0;
        for (int val = 0; val < 1000; val ++)
            if (ap[val] == 0)
            {
                dp[i][j] = val, ok = 1;
                break;
            }
        if (ok == 0)
        {
            printf ("fuck\n");
            return 0;
        }
        for (auto it = v.begin (); it != v.end () ;it ++)
            ap[*it] = 0;
    }
for (int i=1; i<=N; i++)
    printf ("%d,\n", dp[i][1]);*/
return 0;
}