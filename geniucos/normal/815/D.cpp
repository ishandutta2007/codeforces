#include<bits/stdc++.h>

using namespace std;

int N, D1, D2, D3, maY[500009], maZ[500009], aib[500009];
const int lg = 18;
pair < int, pair < int, int > > a[500009];

long long ansQ, sum[2000009], lzy[2000009];
void split (int nod, int st, int dr)
{
    if (lzy[nod] == 0) return ;
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    lzy[f1] += lzy[nod], lzy[f2] += lzy[nod];
    sum[f1] += 1LL * lzy[nod] * (mij - st + 1), sum[f2] += 1LL * lzy[nod] * (dr - mij);
    lzy[nod] = 0;
}

void UpdateSegm (int nod, int st, int dr, int x, int y, int val)
{
    if (x <= st && dr <= y)
    {
        lzy[nod] += val, sum[nod] += 1LL * val * (dr - st + 1);
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    split (nod, st, dr);
    if (x <= mij) UpdateSegm (f1, st, mij, x, y, val);
    if (mij < y) UpdateSegm (f2, mij + 1, dr, x, y, val);
    sum[nod] = sum[f1] + sum[f2];
}

void Query (int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
    {
        if (x == st) ansQ = sum[nod];
        else ansQ += sum[nod];
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    split (nod, st, dr);
    if (x <= mij) Query (f1, st, mij, x, y);
    if (mij < y) Query (f2, mij + 1, dr, x, y);
}

set < pair < int, int > > S;

int vll[100009];
void add (int st, int dr, int val) {UpdateSegm (1, 1, D2, st, dr, val);}
long long qry (int st, int dr) {Query (1, 1, D2, st, dr); return ansQ;}

void U (int y, int z) {while (y <= D2) aib[y] = max (aib[y], z), y += y - (y & (y - 1));}
int Q (int y) {int ans = 0; while (y) ans = max (ans, aib[y]), y &= y - 1; return ans;}
int lastGreater (int val)
{
    int pos = 0;
    for (int i=lg; i>=0; i--)
        if (pos + (1 << i) <= D2 && aib[pos + (1 << i)] <= val)
            pos |= 1 << i;
    return D2 - pos;
}

void pushPoint (pair < int, int > P)
{
    if (Q (D2 + 1 - P.first) >= P.second) return ;
    auto it = S.lower_bound (P); it --;
    if (it->first < P.first)
        add (it->first + 1, P.first, P.second - Q (D2 + 1 - P.first));
    while (it->second < P.second)
    {
        auto it2 = it; it2 --;
        add (it2->first + 1, it->first, P.second - it->second);
        S.erase (it), it = it2;
    }
    S.insert (P), U (D2 + 1 - P.first, P.second);
}

long long getVal (int minY, int minZ)
{
    int Y = lastGreater (minZ);
    long long all = 1LL * (D2 - minY) * (D3 - minZ);
    if (Y <= minY) return all;
    all -= (qry (minY + 1, Y) - 1LL * (Y - minY) * minZ);
    return all;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d", &N, &D1, &D2, &D3);
for (int i=1; i<=N; i++)
    scanf ("%d %d %d", &a[i].first, &a[i].second.first, &a[i].second.second);
sort (a + 1, a + N + 1);
maY[N + 1] = maZ[N + 1] = 0;
for (int i=N; i>=1; i--)
{
    maY[i] = max (maY[i + 1], a[i].second.first);
    maZ[i] = max (maZ[i + 1], a[i].second.second);
}
S.insert ({0, D3 + 1});
int i = 0;
long long lstVal = -1, ans = 0;
bool anyChange = 1;
for (int X=1; X<=D1; X++)
{
    while (i + 1 <= N && a[i + 1].first < X)
        i ++, pushPoint (a[i].second), anyChange = 1;
    if (anyChange)
        lstVal = getVal (maY[i + 1], maZ[i + 1]), anyChange = 0;
    ans += lstVal;
}
printf ("%I64d\n", ans);
return 0;
}