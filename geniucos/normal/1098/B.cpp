#include<bits/stdc++.h>

using namespace std;

int best, N, M;
char **sir, **ans;

int code (char c)
{
    if (c == 'A') return 1;
    if (c == 'C') return 2;
    if (c == 'G') return 3;
    return 4;
}

char getCh (int c)
{
    if (c == 1) return 'A';
    if (c == 2) return 'C';
    if (c == 3) return 'G';
    return 'T';
}

void tryLines ()
{
    int bestSoFar = N * M + 2, a1 = -1, b1 = -1, a2 = -1, b2 = -1;
    for (int i1 = 1; i1<=4; i1++)
        for (int j1=i1 + 1; j1<=4; j1++)
        {
            int i2 = 1, j2;
            while (i2 == i1 || i2 == j1) i2 ++;
            j2 = i2 + 1;
            while (j2 == i1 || j2 == j1) j2 ++;
            int currCost = 0;
            for (int i=1; i<=N; i++)
            {
                int x = i1, y = j1;
                if (i % 2 == 0)
                    x = i2, y = j2;
                int cnt1 = 0, cnt2 = 0;
                for (int j=1; j<=M; j+=2)
                    cnt1 += (sir[i][j] != x),
                    cnt2 += (sir[i][j] != y);
                for (int j=2; j<=M; j+=2)
                    cnt1 += (sir[i][j] != y),
                    cnt2 += (sir[i][j] != x);
                currCost += min (cnt1, cnt2);
            }
            if (currCost < bestSoFar)
                bestSoFar = currCost,
                a1 = i1, b1 = j1, a2 = i2, b2 = j2;
        }
    if (bestSoFar < best)
    {
        best = bestSoFar;
        int i1 = a1, j1 = b1, i2 = a2, j2 = b2;
        for (int i=1; i<=N; i++)
        {
            int x = i1, y = j1;
            if (i % 2 == 0)
                x = i2, y = j2;
            int cnt1 = 0, cnt2 = 0;
            for (int j=1; j<=M; j+=2)
                cnt1 += (sir[i][j] != x),
                cnt2 += (sir[i][j] != y);
            for (int j=2; j<=M; j+=2)
                cnt1 += (sir[i][j] != y),
                cnt2 += (sir[i][j] != x);
            if (cnt1 > cnt2)
                swap (x, y);
            for (int j=1; j<=M; j+=2)
                ans[i][j] = x;
            for (int j=2; j<=M; j+=2)
                ans[i][j] = y;
        }
    }
}

void tryColumns ()
{
    int bestSoFar = N * M + 2, a1 = -1, b1 = -1, a2 = -1, b2 = -1;
    for (int i1 = 1; i1<=4; i1++)
        for (int j1=i1 + 1; j1<=4; j1++)
        {
            int i2 = 1, j2;
            while (i2 == i1 || i2 == j1) i2 ++;
            j2 = i2 + 1;
            while (j2 == i1 || j2 == j1) j2 ++;
            int currCost = 0;
            for (int j=1; j<=M; j++)
            {
                int x = i1, y = j1;
                if (j % 2 == 0)
                    x = i2, y = j2;
                int cnt1 = 0, cnt2 = 0;
                for (int i=1; i<=N; i+=2)
                    cnt1 += (sir[i][j] != x),
                    cnt2 += (sir[i][j] != y);
                for (int i=2; i<=N; i+=2)
                    cnt1 += (sir[i][j] != y),
                    cnt2 += (sir[i][j] != x);
                currCost += min (cnt1, cnt2);
            }
            if (currCost < bestSoFar)
                bestSoFar = currCost,
                a1 = i1, b1 = j1, a2 = i2, b2 = j2;
        }
    if (bestSoFar < best)
    {
        best = bestSoFar;
        int i1 = a1, j1 = b1, i2 = a2, j2 = b2;
        for (int j=1; j<=M; j++)
        {
            int x = i1, y = j1;
            if (j % 2 == 0)
                x = i2, y = j2;
            int cnt1 = 0, cnt2 = 0;
            for (int i=1; i<=N; i+=2)
                cnt1 += (sir[i][j] != x),
                cnt2 += (sir[i][j] != y);
            for (int i=2; i<=N; i+=2)
                cnt1 += (sir[i][j] != y),
                cnt2 += (sir[i][j] != x);
            if (cnt1 > cnt2)
                swap (x, y);
            for (int i=1; i<=N; i+=2)
                ans[i][j] = x;
            for (int i=2; i<=N; i+=2)
                ans[i][j] = y;
        }
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
sir = new char*[N + 3], ans = new char*[N + 3];
for (int i=1; i<=N; i++)
{
    sir[i] = new char[M + 3];
    ans[i] = new char[M + 3];
    scanf ("%s", sir[i] + 1);
    for (int j=1; j<=M; j++)
        sir[i][j] = code (sir[i][j]);
}
best = N * M + 10;
tryLines ();
tryColumns ();
//fprintf (stderr, "%d\n", best);
for (int i=1; i<=N; i++, printf ("\n"))
    for (int j=1; j<=M; j++)
        printf ("%c", getCh (ans[i][j]));
return 0;
}