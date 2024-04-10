#include<bits/stdc++.h>

using namespace std;

int N, a[100009], ord[100009], t[100009];
long long ans[100009], sum[100009];
bool ap[100009];

int tata (int nod)
{
    if (t[nod] == nod) return nod;
    return t[nod] = tata (t[nod]);
}

void unite (int x, int y)
{
    x = tata (x), y = tata (y);
    if (x == y) return ;
    t[x] = y, sum[y] += sum[x];
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), t[i] = i, sum[i] = a[i];
for (int i=1; i<=N; i++)
    scanf ("%d", &ord[i]);
long long maxi = 0;
for (int i=N; i>=1; i--)
{
    ans[i] = maxi;
    int p = ord[i];
    if (ap[p - 1] != 0) unite (p - 1, p);
    if (ap[p + 1] != 0) unite (p + 1, p);
    ap[p] = 1;
    if (sum[tata (p)] > maxi) maxi = sum[tata (p)];
}
for (int i=1; i<=N; i++)
    printf ("%I64d\n", ans[i]);
return 0;
}