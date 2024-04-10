#include<bits/stdc++.h>

using namespace std;

const int maxN = 509;
int N, M, a[maxN][maxN], b[maxN][maxN], l[maxN], c[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
        scanf ("%d", &a[i][j]), l[i] ^= a[i][j], c[j] ^= a[i][j];
for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
        scanf ("%d", &b[i][j]), l[i] ^= b[i][j], c[j] ^= b[i][j];
bool ok = 1;
for (int i=1; i<=N; i++)
    if (l[i])
        ok = 0;
for (int j=1; j<=M; j++)
    if (c[j])
        ok = 0;
if (ok) printf ("Yes\n");
else printf ("No\n");
/*for (int all = 0; all < 2; all ++)
    for (int firstLine = 0; firstLine < 2; firstLine ++)
    {
        for (int j=1; j<=M; j++)
            c[j] = a[1][j] ^ all ^ firstLine ^ b[1][j];
        l[1] = firstLine;
        for (int i=2; i<=N; i++)
            l[i] = a[i][1] ^ all ^ c[1] ^ b[i][1];
        bool ok = 1;
        for (int i=1; i<=N; i++)
            for (int j=1; j<=M; j++)
                if (a[i][j] ^ all ^ l[i] ^ c[j] ^ b[i][j])
                {
                    ok = 0;
                    i = N + 1;
                    break;
                }
        if (!ok)
            continue;
        int xorL = 0, xorC = 0, cntL = 0, cntC = 0;
        for (int i=1; i<=N; i++)
            xorL ^= l[i], cntL += l[i];
        for (int i=1; i<=M; i++)
            xorC ^= c[i], cntC += c[i];
        if (xorL || xorC)
            continue;
        printf ("Yes\n");
        exit(0);
        /// must K % 2 = all operations
        /// from K operations can alter up to 2K rows,
    }*/
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/