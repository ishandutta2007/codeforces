#include<bits/stdc++.h>

using namespace std;

int K, M, p, nr, val[100009], cnt[100009];
pair < int, int > bg[100009], nd[100009];

void read ()
{
    int L;
    scanf ("%d %d %d", &L, &K, &M);
    while (L --)
    {
        int x;
        scanf ("%d", &x);
        if (nr > 0 && val[nr] == x)
        {
            if (++cnt[nr] == K) nr --;
        }
        else val[++nr] = x, cnt[nr] = 1;
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

read ();
for (int i=1, j = nr; i<=j; i++, j--)
{
    if (val[i] != val[j])
    {
        long long ans = 0;
        for (int k=1; k<=p; k++)
            ans += bg[k].second + nd[k].second;
        for (int k=i; k<=j; k++)
            ans += 1LL * M * cnt[k];
        printf ("%I64d\n", ans);
        return 0;
    }
    if (i != j)
    {
        bg[++p] = {val[i], cnt[i]};
        nd[p] = {val[j], cnt[j]};
        if ((cnt[i] + cnt[j]) % K != 0)
        {
            long long ans = 1LL * ((cnt[i] + cnt[j]) % K) * (M - 1);
            for (int k=1; k<=p; k++)
                ans += bg[k].second + nd[k].second;
            for (int k=i + 1; k<j; k++)
                ans += 1LL * M * cnt[k];
            printf ("%I64d\n", ans);
            return 0;
        }
        continue;
    }
    int aux = (1LL * cnt[i] * M) % K;
    if (aux > 0)
    {
        long long ans = aux;
        for (int k=1; k<=p; k++)
            ans += bg[k].second + nd[k].second;
        printf ("%I64d\n", ans);
        return 0;
    }
    break;
}
long long ans = 0;
while (p > 0 && (bg[p].second + nd[p].second) % K == 0) p --;
ans = (bg[p].second + nd[p].second) % K;
for (int i=1; i<p; i++)
    ans += bg[i].second + nd[i].second;
printf ("%I64d\n", ans);
return 0;
}