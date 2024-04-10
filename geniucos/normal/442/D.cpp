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

int N, dp[1000009], T[1000009], Max[1000009], ma[1000009];
vector < int > fii[1000009];

void solve (int nod, int fiu)
{
    while (1)
    {
        if (nod == 0) break;
        if (dp[nod] - dp[fiu] >= 1) break;
        if (dp[fiu] > Max[nod]) Max[nod] = dp[fiu];
        int curr = 0, ans = 10000000;
        for (int i=0; i<fii[nod].size (); i++)
        {
            ma[i] = curr;
            if (dp[fii[nod][i]] > curr)
                curr = dp[fii[nod][i]];
        }
        curr = 0;
        for (int i=fii[nod].size () - 1; i>=0; i--)
        {
            if (curr > ma[i]) ma[i] = curr;
            int cur2 = ma[i] + 1;
            if (dp[fii[nod][i]] > cur2) cur2 = dp[fii[nod][i]];
            if (cur2 < ans) ans = cur2;
            if (dp[fii[nod][i]] > curr)
                curr = dp[fii[nod][i]];
        }
        if (dp[nod] == ans) break;
        dp[nod] = ans;
        fiu = nod, nod = T[nod];
    }
}

void Read (int &x);

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

Read (N), N ++;
int maxi = 0;
for (int i=2; i<=N; i++)
{
    Read (T[i]);
    dp[i] = 1;
    fii[T[i]].push_back (i);
    solve (T[i], i);
    printf ("%d ", Max[1]);
}
//printf ("%d\n", maxi);

return 0;
}

#define maxl 100000
int pos = maxl - 1;
char sir[maxl];

void Next ()
{
    if (++pos == maxl)
        fread (sir, 1, maxl, stdin), pos = 0;
}

void Read (int &x)
{
    for (; sir[pos] < '0' || sir[pos] > '9'; Next ());
    for (x = 0; sir[pos] >= '0' && sir[pos] <= '9'; Next ()) x = x * 10 + sir[pos] - '0';
}