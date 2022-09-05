#include<cstdio>
#include<algorithm>

using namespace std;

int nr, x[1009], y[1009], A[1009], N, K, a[1009], p[1009];
double sol, P;

void back (int poz)
{
    if (poz == K + 1)
    {
        for (int i=1; i<=N; i++)
            A[i] = a[i];
        for (int i=1; i<=K; i++)
            reverse (A + x[p[i]], A + y[p[i]] + 1);
        int inv = 0;
        for (int i=1; i<=N; i++)
            for (int j=i+1; j<=N; j++)
                if (A[i] > A[j])
                    inv ++;
        sol = (double) sol + inv * P;
        return;
    }
    for (int i=1; i<=nr; i++)
    {
        p[poz] = i;
        back (poz + 1);
    }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);

for (int i=1; i<=N; i++)
    for (int j=i; j<=N; j++)
        x[++nr] = i, y[nr] = j;

P = 1.0;
for (int i=1; i<=K; i++)
    P = (double) P / nr;

back (1);

printf ("%.11lf\n", sol);

return 0;
}