#include<bits/stdc++.h>

using namespace std;

int nr, N, M, aint[2000018];

int gcd (int a, int b)
{
    int r;
    while (b)
        r = a % b, a = b, b = r;
    return a;
}

void Build (int nod, int st, int dr)
{
    if (st == dr)
    {
        scanf ("%d", &aint[nod]);
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    Build (f1, st, mij);
    Build (f2, mij + 1, dr);
    aint[nod] = gcd (aint[f1], aint[f2]);
}

void Update (int nod, int st, int dr, int pos, int val)
{
    if (st == dr)
    {
        aint[nod] = val;
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    if (pos <= mij) Update (f1, st, mij, pos, val);
    else Update (f2, mij + 1, dr, pos, val);
    aint[nod] = gcd (aint[f1], aint[f2]);
}

bool Query (int nod, int st, int dr, int x, int y, int d)
{
    if (x <= st && dr <= y)
    {
        if (aint[nod] % d == 0) return 1;
        return 0;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    bool ans = 1;
    if (x <= mij) ans &= Query (f1, st, mij, x, y, d);
    if (mij < y && ans == 1) ans &= Query (f2, mij + 1, dr, x, y, d);
    return ans;
}

pair < int, pair < int, int > > v[2018];
void doSplit (int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
    {
        v[++nr] = {nod, {st, dr}};
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    if (x <= mij) doSplit (f1, st, mij, x, y);
    if (mij < y) doSplit (f2, mij + 1, dr, x, y);
}

bool eOk (int st, int dr, int val)
{
    if (st > dr) return 1;
    bool ans = Query (1, 1, N, st, dr, val);
    return ans;
}

int getWrong (int nod, int st, int dr, int val)
{
    if (st == dr) return st;
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    if (aint[f1] % val != 0) return getWrong (f1, st, mij, val);
    return getWrong (f2, mij + 1, dr, val);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), Build (1, 1, N);
scanf ("%d", &M);
while (M --)
{
    int type;
    scanf ("%d", &type);
    if (type == 2)
    {
        int val, pos;
        scanf ("%d %d", &pos, &val);
        Update (1, 1, N, pos, val);
        continue;
    }
    int x, y, val, pos = -1;
    scanf ("%d %d %d", &x, &y, &val), nr = 0;
    doSplit (1, 1, N, x, y);
    for (int i=1; i<=nr; i++)
        if (aint[v[i].first] % val != 0)
        {
            pos = getWrong (v[i].first, v[i].second.first, v[i].second.second, val);
            break;
        }
    if (pos == -1)
    {
        printf ("YES\n");
        continue;
    }
    bool ans = eOk (pos + 1, y, val);
    if (ans == 1) ans &= eOk (x, pos - 1, val);
    if (ans) printf ("YES\n");
    else printf ("NO\n");
}

return 0;
}