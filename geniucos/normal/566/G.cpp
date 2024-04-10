#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

int nr, N, M, maxA, maxB, maxC, maxD, x, y, st[100009];
pair < int, int > P[100009], Q[100009], O = make_pair (0, 0);

long long mod (long long x)
{
    if (x < 0) return -x;
    return x;
}

long long det (pair < int, int > a, pair < int, int > b, pair < int, int > c)
{
    return 1LL * a.x * b.y + 1LL * b.x * c.y + 1LL * c.x * a.y - 1LL * a.x * c.y - 1LL * b.x * a.y - 1LL * c.x * b.y;
}

bool in (pair < int, int > a, pair < int, int > p, pair < int, int > b)
{
    long long x1 = mod (det (a, O, p)), x2 = mod (det (b, O, p)), x3 = mod (det (a, b, p)), xT = mod (det (a, b, O));
    return (x1 + x2 + x3 == xT);
}

bool cmp (pair < int, int > a, pair < int, int > b)
{
    return 1LL * a.x * b.y < 1LL * b.x * a.y;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
scanf ("%d %d", &x, &y);
for (int i=1; i<=N; i++)
{
    int a, b;
    scanf ("%d %d", &a, &b);
    P[i] = make_pair (a, b);
    if (i == 1) maxA = a, maxB = b;
    else maxA = max (maxA, a), maxB = max (maxB, b);
}
for (int i=1; i<=M; i++)
{
    int a, b;
    scanf ("%d %d", &a, &b);
    Q[i] = make_pair (a, b);
    if (i == 1) maxC = a, maxD = b;
    else maxC = max (maxC, a), maxD = max (maxD, b);
}
Q[M + 1] = make_pair (maxC, 0), Q[M + 2] = make_pair (0, maxD), M += 2;
for (int i=1; i<=M; i++)
    Q[i].y = -Q[i].y;
sort (Q + 1, Q + M + 1);
for (int i=1; i<=M; i++)
    Q[i].y = -Q[i].y;
nr = 2, st[1] = 1, st[2] = 2;
for (int i=3; i<=M; i++)
{
    while (nr >= 2 && det (Q[st[nr - 1]], Q[st[nr]], Q[i]) >= 0) nr --;
    st[++nr] = i;
}
//for (int i=1; i<=nr; i++)
  //  printf ("%d %d\n", Q[st[i]].x, Q[st[i]].y);
sort (P + 1, P + N + 1, cmp);
int j = 1;
for (int i=1; i<=N; i++)
{
    while (j < nr && in (Q[st[j]], P[i], Q[st[j + 1]]) == 0) j ++;
    if (j == nr || det (Q[st[j]], P[i], Q[st[j + 1]]) == 0)
    {
        printf ("Max\n");
        return 0;
    }
}
printf ("Min\n");
return 0;
}