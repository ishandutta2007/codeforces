#include<bits/stdc++.h>

using namespace std;

int dis, N, *aib[100009], x[100009], t[100009], *T[100009], type[100009], L[100009];
pair < int, int > v[100009];

int pow (int a, int b, int mod)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = (1LL * p * a) % mod;
        a = (1LL * a * a) % mod;
    }
    return p;
}

void Update (int lin, int pos, int val)
{
    while (pos <= L[lin])
    {
        aib[lin][pos] += val;
        pos += pos - (pos & (pos - 1));
    }
}

int Query (int lin, int pos)
{
    int sum = 0;
    while (pos)
    {
        sum += aib[lin][pos];
        pos &= pos - 1;
    }
    return sum;
}

int GetId (int lin, int val)
{
    int p = 1, u = L[lin], mij, ras = -1;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (T[lin][mij] <= val) p = mij + 1, ras = mij;
        else u = mij - 1;
    }
    return ras;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d %d %d", &type[i], &t[i], &x[i]), v[i] = make_pair (x[i], i);
sort (v + 1, v + N + 1);
for (int i=1; i<=N; i++)
{
    int j;
    for (j=i; j<=N; j++)
        if (v[j].first != v[i].first) break;
    j --;
    ///[i, j]
    L[++dis] = j - i + 1;
    T[dis] = new int[L[dis] + 3] (), aib[dis] = new int[L[dis] + 3] ();
    int curr = 0;
    for (int k=i; k<=j; k++)
        T[dis][++curr] = t[v[k].second], x[v[k].second] = dis;
    sort (T[dis] + 1, T[dis] + curr + 1);
    i = j;
}
for (int i=1; i<=N; i++)
{
    if (type[i] <= 2)
    {
        int cat = 1, pos;
        if (type[i] == 2) cat = -1;
        pos = GetId (x[i], t[i]);
        Update (x[i], pos, cat);
        continue;
    }
    int pos = GetId (x[i], t[i]);
    printf ("%d\n", Query (x[i], pos));
}
return 0;
}