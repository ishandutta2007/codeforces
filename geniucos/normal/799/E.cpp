#include<bits/stdc++.h>

using namespace std;

int N, M, K, lg = 17, aib1[200009], where[200009], h[4][200009], l[4], ap[200009];
long long ans, tot, aib2[200009];
pair < int, int > a[200009];

void U (int pos, int v1, int v2){while (pos <= N){aib1[pos] += v1, aib2[pos] += v2;pos += pos - (pos & (pos - 1));}}
void adVal (int i) {U (where[i], +1, a[where[i]].first);}
void delVal (int i) {U (where[i], -1, -a[where[i]].first);}

long long Query (int firstM)
{
    int pos = 0;
    long long ans = 0;
    for (int i=lg; i>=0; i--)
        if (pos + (1 << i) <= N && aib1[pos + (1 << i)] <= firstM)
            pos |= 1 << i, firstM -= aib1[pos], ans += aib2[pos];
    return ans;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &M, &K);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i].first), a[i].second = i;
sort (a + 1, a + N + 1);
for (int i=1; i<=N; i++)
    where[a[i].second] = i;
int L, x;
scanf ("%d", &L);
while (L --)
    scanf ("%d", &x), ap[x] |= 1;
scanf ("%d", &L);
while (L --)
    scanf ("%d", &x), ap[x] |= 2;
for (int i=1; i<=N; i++)
    h[ ap[a[i].second] ] [++ l [ap[a[i].second]]] = a[i].second;
for (int i=1; i<=l[0]; i++)
    adVal (h[0][i]);
for (int i=1; i<=l[3]; i++)
    adVal (h[3][i]);
tot = 0, ans = -1;
for (int i=1; i<=l[1]; i++)
    tot += a[where[h[1][i]]].first;
for (int i=1; i<=l[2]; i++)
    tot += a[where[h[2][i]]].first;
for (int i=0; i<=K && i<=l[3]; i++)
{
    if (i != 0)
        tot += a[where[h[3][i]]].first, delVal (h[3][i]);
    while (l[1] + i > K)
        tot -= a[where[h[1][l[1]]]].first, adVal (h[1][l[1]]), l[1] --;
    while (l[2] + i > K)
        tot -= a[where[h[2][l[2]]]].first, adVal (h[2][l[2]]), l[2] --;
    if (l[1] + i == K && l[2] + i == K && l[1] + l[2] + i <= M)
    {
        long long curr = Query (M - l[1] - l[2] - i) + tot;
        if (ans == -1 || curr < ans)
            ans = curr;
    }
}
printf ("%I64d\n", ans);
return 0;
}