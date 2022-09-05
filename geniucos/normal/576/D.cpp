#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<bitset>
#include<string>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int INF, N, M, a[209], b[209], c[209], dp[209];
vector < int > v;
queue < int > cc;

struct matrix
{
    bitset < 160 > lin[160];
    void unit ()
    {
        for (int i=1; i<=N; i++)
            lin[i][i] = 1;
    }
    void afis ()
    {
        for (int i=1; i<=N; i++, printf ("\n"))
            for (int j=1; j<=N; j++)
                if (lin[i][j] == 1) printf ("1");
                else printf ("0");
        printf ("\n");
    }
    matrix& operator *= (const matrix &other)
    {
        bitset < 160 > nou[160];
        for (int i=1; i<=N; i++)
            for (int j=1; j<=N; j++)
                if (lin[i][j] == 1)
                    nou[i] |= other.lin[j];
        for (int i=1; i<=N; i++)
            lin[i] = nou[i];
        return *this;
    }
}curr, acu;

matrix pow (matrix a, int B)
{
    matrix ans;
    ans.unit ();
    for (int i=0; (1<<i) <= B; i++)
    {
        if (B & (1<<i)) ans *= a;
        a *= a;
    }
    return ans;
}

void Try (int T)
{
    for (int j=1; j<=N; j++)
        if (curr.lin[1][j] == 1) dp[j] = T, cc.push (j);
        else dp[j] = INF;

    while (!cc.empty ())
    {
        int nod = cc.front ();
        cc.pop ();
        for (int i=1; i<=N; i++)
            if (acu.lin[nod][i] == 1 && dp[i] > dp[nod] + 1)
            {
                dp[i] = dp[nod] + 1;
                cc.push (i);
            }
    }

    if (dp[N] < INF)
    {
        printf ("%d\n", dp[N]);
        exit (0);
    }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=M; i++)
    scanf ("%d %d %d", &a[i], &b[i], &c[i]), v.push_back (c[i]);
sort (v.begin (), v.end ());
v.erase (unique (v.begin (), v.end ()), v.end ());
curr.unit ();
if (v[0] != 0)
{
    printf ("Impossible\n");
    return 0;
}
INF = ((1<<30) - 2) << 1;
v.push_back (0);
for (int i=1; i<v.size (); i++)
{
    for (int j=1; j<=M; j++)
        if (c[j] == v[i-1])
            acu.lin[a[j]][b[j]] = 1;
    Try (v[i-1]);
    if (i != v.size () - 1) curr *= pow (acu, v[i] - v[i-1]);
}
printf ("Impossible\n");
return 0;
}