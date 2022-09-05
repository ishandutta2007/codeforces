#include<cstdio>
#include<bitset>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int v1, mod, N, M, nr, inv[200009], F[200009], st[200009], dr[200009], sum[800009], upd[800009], tip[200009], nod[200009], val[200009], order[200009], ans_aint, T[200009];
vector < int > fii[200009];

int pow (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = (1LL * p * a) % mod;
        a = (1LL * a * a) % mod;
    }
    return p;
}

void dfs (int nod)
{
    order[++nr] = nod, st[nod] = nr;
    for (vector < int > :: iterator it = fii[nod].begin (); it != fii[nod].end (); it ++)
        dfs (*it);
    dr[nod] = nr;
}

void build (int nod, int st, int dr)
{
    upd[nod] = 1;
    if (st == 1) sum[nod] = v1;
    if (st == dr) return ;
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 + 1;
    build (f1, st, mij);
    build (f2, mij + 1, dr);
}

void split (int nod, int f1, int f2)
{
    if (upd[nod] == 1) return ;
    upd[f1] = (1LL * upd[f1] * upd[nod]) % mod, upd[f2] = (1LL * upd[f2] * upd[nod]) % mod;
    sum[f1] = (1LL * sum[f1] * upd[nod]) % mod, sum[f2] = (1LL * sum[f2] * upd[nod]) % mod;
    upd[nod] = 1;
}

void Propagate_and_fix (int nod, int st, int dr, int pos, int val)
{
    if (st == dr)
    {
        sum[nod] = (1LL * upd[nod] * val) % mod;
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 + 1;
    split (nod, f1, f2);
    if (pos <= mij) Propagate_and_fix (f1, st, mij, pos, val);
    else Propagate_and_fix (f2, mij + 1, dr, pos, val);
    sum[nod] = sum[nod << 1] + sum[(nod << 1) + 1];
    if (sum[nod] >= mod) sum[nod] -= mod;
}

void Update (int nod, int st, int dr, int x, int y, int val)
{
    if (x <= st && dr <= y)
    {
        upd[nod] = (1LL * upd[nod] * val) % mod;
        sum[nod] = (1LL * sum[nod] * val) % mod;
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 + 1;
    split (nod, f1, f2);
    if (x <= mij) Update (f1, st, mij, x, y, val);
    if (y > mij) Update (f2, mij + 1, dr, x, y, val);
    sum[nod] = sum[nod << 1] + sum[(nod << 1) + 1];
    if (sum[nod] >= mod) sum[nod] -= mod;
}

void Query (int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
    {
        ans_aint += sum[nod];
        if (ans_aint >= mod) ans_aint -= mod;
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 + 1;
    split (nod, f1, f2);
    if (x <= mij) Query (f1, st, mij, x, y);
    if (y > mij) Query (f2, mij + 1, dr, x, y);
}

int Get_coef (int nod, int st, int dr, int pos)
{
    if (st == dr) return upd[nod];
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 + 1;
    split (nod, f1, f2);
    if (pos <= mij) return Get_coef (f1, st, mij, pos);
    return Get_coef (f2, mij + 1, dr, pos);
}

int Get_Sum (int left, int right)
{
    ans_aint = 0;
    Query (1, 1, nr, left, right);
    return ans_aint;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &v1, &M), mod = 1e9 + 7;
N = 1;
for (int i=1; i<=M; i++)
{
    scanf ("%d %d", &tip[i], &nod[i]);
    if (tip[i] == 1) scanf ("%d", &val[i]), fii[nod[i]].push_back (++N);
}
for (int i=1; i<=N; i++)
    inv[i] = pow (i, mod - 2);
dfs (1);
build (1, 1, nr);
N = 1, F[1] = 0;///nr_fii
for (int i=1; i<=M; i++)
{
    if (tip[i] == 1)
    {
        T[++N] = nod[i];
        int mult = (1LL * (F[nod[i]] + 2) * inv[F[nod[i]] + 1]) % mod;
        Update (1, 1, nr, st[nod[i]], dr[nod[i]], mult);
        Propagate_and_fix (1, 1, nr, st[N], val[i]);
        F[nod[i]] ++;
        continue;
    }
    int sm = Get_Sum (st[nod[i]], dr[nod[i]]);
    if (nod[i] == 1) printf ("%d\n", sm);
    else
    {
        int coef = Get_coef (1, 1, nr, st[T[nod[i]]]);
        sm = (1LL * sm * pow (coef, mod - 2)) % mod;
        printf ("%d\n", sm);
    }
}

return 0;
}