#include<bits/stdc++.h>

using namespace std;

int N, M, dp[200009], buc[200009], best[200009], a[200009], st[100009], dr[100009], l[100009], lst[50];
pair < int, int > b[200009];

int gcd (int a, int b)
{
    int r;
    while (b) r = a % b, a = b, b = r;
    return a;
}

int srch (int i, int val)
{
    int p = st[i], u = dr[i], mij;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (b[mij].first == val) return b[mij].second;
        if (b[mij].first < val) p = mij + 1;
        else u = mij - 1;
    }
    return -1;
}

bool bate (int i, int j)
{
    if (i == -1 || j == -1) return 0;
    int l1 = l[buc[i]], l2 = l[buc[j]];
    i -= st[buc[i]], j -= st[buc[j]];
    i -= j;
    if (i < 0) i = -i;
    if (i % gcd (l1, l2) != 0) return 0;
    return 1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &l[i]), st[i] = dr[i - 1] + 1, dr[i] = st[i] + l[i] - 1;
    for (int j=st[i]; j<=dr[i]; j++)
        scanf ("%d", &a[j]), buc[j] = i, b[j] = make_pair (a[j], j);
    sort (b + st[i], b + dr[i] + 1);
}
for (int i=1; i<=N; i++)
{
    for (int curr = st[i]; curr <= dr[i]; curr++)
    {
        dp[curr] = 1;
        int P = srch (i - 1, a[curr]);
        if (!bate (P, curr))
        {
            if (best[a[curr]] == 0) best[a[curr]] = 1;
            continue;
        }
        dp[curr] = dp[P] + 1;
        for (int j=1; j<=40; j++)
            if (lst[j] != 0 && i - lst[j] < dp[curr])
            {
                int pos = srch (lst[j], a[curr]);
                if (!bate (pos, curr))
                {
                    dp[curr] = i - lst[j];
                    continue;
                }
            }
        if (dp[curr] > best[a[curr]]) best[a[curr]] = dp[curr];
    }
    lst[l[i]] = i;
}
for (int i=1; i<=M; i++)
    printf ("%d\n", best[i]);
return 0;
}