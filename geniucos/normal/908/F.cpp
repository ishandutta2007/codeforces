#include<bits/stdc++.h>

using namespace std;

int N, M, pos[300009], x[300009], type[300009], cnt[300009];
long long before, after, between[300009];

void Read ()
{
    scanf ("%d", &N);
    bool any2 = 0;
    for (int i=1; i<=N; i++)
    {
        char c;
        scanf ("%d %c\n", &x[i], &c);
        if (c == 'G') type[i] = 2;
        else
        if (c == 'R') type[i] = 1;
        else type[i] = 0;
        any2 |= (type[i] == 2);
    }
    if (!any2)
    {
        long long ans = 0;
        int mnx[2], mxx[2];
        mnx[0] = mnx[1] = -1;
        for (int i=1; i<=N; i++)
        {
            if (mnx[type[i]] == -1)
                mnx[type[i]] = x[i];
            mxx[type[i]] = x[i];
        }
        if (mnx[0] != -1) ans += mxx[0] - mnx[0];
        if (mnx[1] != -1) ans += mxx[1] - mnx[1];
        printf ("%I64d\n", ans);
        exit (0);
    }
}

void Prec ()
{
    for (int i=1; i<=N; i++)
        if (type[i] == 2)
            pos[++M] = i;
    for (int i=1; i<M; i++)
    {
        bool any[2];
        any[0] = any[1] = 0;
        for (int j=pos[i] + 1; j<pos[i + 1]; j++)
            any[type[j]] = 1;
        for (int t=0; t<2; t++)
            if (any[t])
            {
                int lst = x[pos[i]], maxi = 0;
                for (int j=pos[i] + 1; j<pos[i + 1]; j++)
                    if (type[j] == t)
                    {
                        if (x[j] - lst > maxi) maxi = x[j] - lst;
                        lst = x[j];
                    }
                if (x[pos[i + 1]] - lst > maxi) maxi = x[pos[i + 1]] - lst;
                between[i] += x[pos[i + 1]] - x[pos[i]] - maxi;
            }
    }

    int mnx[2]; mnx[0] = mnx[1] = -1;
    for (int i=1; i<pos[1]; i++)
    {
        if (mnx[type[i]] == -1)
            mnx[type[i]] = x[i];
    }
    if (mnx[0] != -1) before += x[pos[1]] - mnx[0];
    if (mnx[1] != -1) before += x[pos[1]] - mnx[1];

    int mxx[2]; mxx[0] = mxx[1] = -1;
    for (int i=pos[M] + 1; i<=N; i++)
        mxx[type[i]] = x[i];
    if (mxx[0] != -1) after += mxx[0] - x[pos[M]];
    if (mxx[1] != -1) after += mxx[1] - x[pos[M]];
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

Read ();
Prec ();
long long ans = before;
for (int i=2; i<=M; i++)
{
    long long curr = x[pos[i]] - x[pos[i - 1]] + min (between[i - 1], (long long) x[pos[i]] - x[pos[i - 1]]);
    ans += curr;
}
ans += after;
printf ("%I64d\n", ans);

return 0;
}