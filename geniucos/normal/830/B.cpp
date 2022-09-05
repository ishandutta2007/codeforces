#include<bits/stdc++.h>

using namespace std;

int N, a[200009];

const int INF = 1e9;
pair < int, int > aint[800009];
pair < int, int > getBst (pair < int, int > v1, pair < int, int > v2)
{
    if (v1.first < v2.first || (v1.first == v2.first && v1.second < v2.second)) return v1;
    return v2;
}

void rfrsh (int nod, int st, int dr, int mij, int f1, int f2)
{
    aint[nod] = getBst (aint[f1], aint[f2]);
}

void Build (int nod, int st, int dr)
{
    if (st == dr)
    {
        aint[nod] = {a[st], st};
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    Build (f1, st, mij);
    Build (f2, mij + 1, dr);
    rfrsh (nod, st, dr, mij, f1, f2);
}

void Update (int nod, int st, int dr, int pos, int val)
{
    if (st == dr)
    {
        aint[nod] = {val, pos};
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    if (pos <= mij) Update (f1, st, mij, pos, val);
    else Update (f2, mij + 1, dr, pos, val);
    rfrsh (nod, st, dr, mij, f1, f2);
}

pair < int, int > ansQ;
void Query (int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
    {
        if (x == st) ansQ = aint[nod];
        else ansQ = getBst (ansQ, aint[nod]);
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    if (x <= mij) Query (f1, st, mij, x, y);
    if (mij < y) Query (f2, mij + 1, dr, x, y);
}

int aib[200009];
void Updt (int pos, int val) {while (pos <= 2 * N) aib[pos] += val, pos += pos - (pos & (pos - 1));}
int Qry (int pos) {int sum = 0; while (pos) sum += aib[pos], pos &= pos - 1; return sum;}
int QrySegm (int st, int dr) {return dr - st + 1 - (Qry (dr) - Qry (st - 1));}

void doDel (int pos)
{
    Updt (pos, +1), Updt (pos + N, +1);
    Update (1, 1, 2 * N, pos, INF);
    Update (1, 1, 2 * N, pos + N, INF);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
for (int i=N + 1; i<=2 * N; i++)
    a[i] = a[i - N];
Build (1, 1, 2 * N);
long long ans = 0;
int pos = 1, sz = N;
while (sz --)
{
    Query (1, 1, 2 * N, pos, pos + N - 1);
    pair < int, int > curr = ansQ;
    int P = curr.second;
    ans += QrySegm (pos, P);
    if (P > N) P -= N;
    doDel (P), pos = P;
}
printf ("%I64d\n", ans);

return 0;
}