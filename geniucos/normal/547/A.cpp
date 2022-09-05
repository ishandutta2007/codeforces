#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>
#include<map>

using namespace std;

int M, H1, H2, A1, A2, X, Y;

int get (int init, int fin, int X, int Y)
{
    int nr = 0;
    while (init != fin)
    {
        nr ++;
        init = ((long long) 1LL * init * X + Y) % M;
        if (nr > M)
            return -1;
    }
    return nr;
}

int getp (int fin, int X, int Y)
{
    int nr = 1, init = ((long long) 1LL * fin * X + Y) % M;
    while (init != fin)
    {
        nr ++;
        init = ((long long) 1LL * init * X + Y) % M;
        if (nr > M + 1)
            return -1;
    }
    return nr;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &M);

scanf ("%d %d", &H1, &A1);
scanf ("%d %d", &X, &Y);
int t1 = get (H1, A1, X, Y), p1 = getp (A1, X, Y);

scanf ("%d %d", &H2, &A2);
scanf ("%d %d", &X, &Y);
int t2 = get (H2, A2, X, Y), p2 = getp (A2, X, Y);

if (t1 == -1 || t2 == -1)
{
    printf ("-1\n");
    return 0;
}

if (t1 == t2)
{
    printf ("%d\n", t1);
    return 0;
}

if (p1 == -1 && p2 == -1)
{
    printf ("-1\n");
    return 0;
}

if (p1 == -1)
    p1 = 0;
else
if (p2 == -1)
    swap (p1, p2), swap (t1, t2), p1 = 0;

for (int X = 0; X <= 2 * M; X ++)
    if (((long long)1LL * X * p1 + t1 - t2) % p2 == 0 && (long long)1LL * X * p1 + t1 - t2 >= 0)
    {
        printf ("%I64d\n", (long long) 1LL * X * p1 + t1);
        return 0;
    }
printf ("-1\n");

//printf ("%d %d\n", g1, g2);

return 0;
}