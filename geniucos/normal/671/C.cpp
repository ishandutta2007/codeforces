#include<bits/stdc++.h>

using namespace std;

int M, lg, N, aint[800009], aib[800009], a[200009], st1[200009], st2[200009], dr1[200009], dr2[200009];
long long ans, sum[800009];
vector < int > v[200009];
vector < pair < int, int > > h[200009];

void Updt (int pos, int val)
{
    while (pos <= N)
    {
        if (val > aib[pos]) aib[pos] = val;
        pos += pos - (pos & (pos - 1));
    }
}

int Qry (int pos)
{
    int ans = 0;
    while (pos)
    {
        if (aib[pos] > ans) ans = aib[pos];
        pos &= pos - 1;
    }
    return ans;
}

void split (int nod, int st, int dr, int mij)
{
    if (aint[nod] == 0) return ;
    aint[nod << 1] = aint[nod << 1 | 1] = aint[nod];
    sum[nod << 1] = 1LL * aint[nod] * (mij - st + 1), sum[nod << 1 | 1] = 1LL * aint[nod] * (dr - mij);
    aint[nod] = 0;
}

void Update (int nod, int st, int dr, int x, int y, int val)
{
    if (x <= st && dr <= y)
    {
        aint[nod] = val, sum[nod] = 1LL * val * (dr - st + 1);
        return ;
    }
    int mij = (st + dr) >> 1;
    split (nod, st, dr, mij);
    if (x <= mij) Update (nod << 1, st, mij, x, y, val);
    if (mij < y) Update (nod << 1 | 1, mij + 1, dr, x, y, val);
    sum[nod] = sum[nod << 1] + sum[nod << 1 | 1];
}

void Query (int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
    {
        ans += sum[nod];
        return ;
    }
    int mij = (st + dr) >> 1;
    split (nod, st, dr, mij);
    if (x <= mij) Query (nod << 1, st, mij, x, y);
    if (mij < y) Query (nod << 1 | 1, mij + 1, dr, x, y);
    sum[nod] = sum[nod << 1] + sum[nod << 1 | 1];
}

void Push (int X, int pos)
{
    int p = 0;
    for (int i=lg; i>=0; i--)
        if (p + (1 << i) <= N && aib[p + (1 << i)] <= X) p += 1 << i;
    if (p == 0 || pos > p) return ;
//    printf ("pe [%d, %d]  %d\n", pos, p, X);
    Update (1, 1, N, pos, p, X);
    Updt (pos, X);
}

int gcd (int a, int b)
{
    int r;
    while (b) r = a % b, a = b, b = r;
    return a;
}

int bruteF (int i, int j)
{
    if (j - i + 1 >= N - 1) return 0;
    int ans = 0, nr = 0, v[109];
    for (int k=1; k<=N; k++)
        if (k < i || k > j) v[++nr] = a[k];
    for (int i=1; i<=nr; i++)
        for (int j=i+1;j<=nr; j++)
        {
            int curr = gcd (v[i], v[j]);
            if (curr > ans) ans = curr;
        }
    return ans;
}

long long Brute ()
{
    long long sol = 0;
    for (int i=1; i<=N; i++)
        for (int j=i; j<=N; j++)
            sol += bruteF (i, j), printf ("%d %d -> %d\n", i, j, bruteF (i, j));
    return sol;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), st1[1] = 1, st2[1] = 2, dr1[1] = N - 1, dr2[1] = N;
if (N == 1)
{
    printf ("0\n");
    return 0;
}
for (int i=1; i<=N; i++)
{
    scanf ("%d", &a[i]);
    if (a[i] > M) M = a[i];
}
for (int i=2; i<=M; i++)
{
    st1[i] = st2[i] = N + 2, dr1[i] = dr2[i] = 0;
    for (int j=i; j<=M; j+=i)
        v[j].push_back (i);
}
for (int i=1; i<=N; i++)
    for (auto it = v[a[i]].begin (); it != v[a[i]].end (); it ++)
    {
        if (i < st1[*it]) st2[*it] = st1[*it], st1[*it] = i;
        else
        if (i < st2[*it]) st2[*it] = i;

        if (i > dr2[*it]) dr1[*it] = dr2[*it], dr2[*it] = i;
        else
        if (i > dr1[*it]) dr1[*it] = i;
    }
for (int i=1; i<=M; i++)
if (st1[i] < dr2[i] && st2[i] <= N && dr1[i] >= 0)
{
    if (st1[i] < dr2[i] - 1) h[dr2[i] - 1].push_back (make_pair (st1[i] + 1, i));
    if (dr1[i] > 1) h[dr1[i] - 1].push_back (make_pair (1, i));
    if (st2[i] < N) h[N].push_back (make_pair (st2[i] + 1, i));
}
/*for (int i=1; i<=N; i++)
    for (auto it = h[i].begin (); it != h[i].end (); it ++)
        printf ("%d %d   %d\n", it->first, i, it->second);*/
for (lg = 0; 1 << lg <= N; lg ++);
lg --;
for (int j=N; j>=1; j--)
{
    for (auto it = h[j].begin (); it != h[j].end (); it ++)
        Push (it->second, it->first);
    Query (1, 1, N, 1, j);
//    printf ("after %d   %I64d\n", j, ans);
}
printf ("%I64d\n", ans);
//printf ("%I64d\n", Brute ());
return 0;
}