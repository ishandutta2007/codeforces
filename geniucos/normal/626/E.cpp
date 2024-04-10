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

int N, v[200009], ha, hb, hc;
long long hs, hn, s[200009];
bool yet;

bool better (int a, int b, int c, int x, int y, int z)
{
    long long s1, n1, s2, n2;
    n1 = N - c + 1 + b - a + 1, n2 = N - z + 1 + y - x + 1;
    s1 = s[b] - s[a - 1] + s[N] - s[c - 1], s2 = s[y] - s[x - 1] + s[N] - s[z - 1];
    ///s1 / n1 > s2 / n2 ?
    return (1LL * n2 * s1 > 1LL * s2 * n1);
}

void add_to_best (int a, int b, int c, int d)
{
    long long S, n;
    n = N - c + 1 + b - a + 1, S = s[b] - s[a - 1] + s[N] - s[c - 1];
    S = S - 1LL * n * v[d];
    ///S / n > hs / hn?
    if (1LL * hn * S > 1LL * hs * n || yet == 0)
        hn = n, hs = S, ha = a, hb = b, hc = c, yet = 1;
}

void Print (int a, int b, int c)
{
    printf ("%d\n", N - c + 1 + (b - a + 1));
    for (int i=a; i<=b; i++)
        printf ("%d ", v[i]);
    for (int i=c; i<=N; i++)
        printf ("%d ", v[i]);
    printf ("\n");
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &v[i]);
sort (v + 1, v + N + 1);
for (int i=1; i<=N; i++)
    s[i] = s[i - 1] + v[i];
for (int i=1; i<=N; i++)
{
    int p=0, u=i - 1, mij,ras=0;
    if (N-i<u)u=N-i;
    u--;
    while(p<=u)
    {
        mij = (p + u) >> 1;
        if (better (i - (mij + 1), i, N - (mij + 1) + 1,
                    i - mij, i, N - mij + 1)) ras = mij + 1, p = mij + 1;
        else u=mij - 1;
    }
    add_to_best (i - ras, i, N - ras + 1, i);
}
Print(ha,hb,hc);
return 0;
}