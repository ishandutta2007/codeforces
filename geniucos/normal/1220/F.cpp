#include<bits/stdc++.h>

using namespace std;

int nr, N, a[400009], stk[400009], lft[400009], rgt[400009], t[400009];

int initialValue[400009], aint[1600009], lzy[1600009];
void build (int nod, int st, int dr)
{
    if (st == dr)
    {
        aint[nod] = initialValue[st];
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    build (f1, st, mij);
    build (f2, mij + 1, dr);
    aint[nod] = max (aint[f1], aint[f2]);
}

void split (int nod, int f1, int f2)
{
    if (lzy[nod] == 0) return ;
    lzy[f1] += lzy[nod], aint[f1] += lzy[nod];
    lzy[f2] += lzy[nod], aint[f2] += lzy[nod];
    lzy[nod] = 0;
}

void update (int nod, int st, int dr, int x, int y, int val)
{
//    if (nod == 1)
  //      fprintf (stderr, "[%d, %d] %d\n", x, y, val);
    if (x <= st && dr <= y)
    {
        aint[nod] += val;
        lzy[nod] += val;
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    split (nod, f1, f2);
    if (x <= mij) update (f1, st, mij, x, y, val);
    if (mij < y) update (f2, mij + 1, dr, x, y, val);
    aint[nod] = max (aint[f1], aint[f2]);
}

void setVal (int nod, int st, int dr, int pos, int val)
{
    if (st == dr)
    {
        aint[nod] = val;
        lzy[nod] = 0;
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    split (nod, f1, f2);
    if (pos <= mij) setVal (f1, st, mij, pos, val);
    else setVal (f2, mij + 1, dr, pos, val);
    aint[nod] = max (aint[f1], aint[f2]);
}

int queryVal (int nod, int st, int dr, int pos)
{
    if (st == dr) return aint[nod];
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    split (nod, f1, f2);
    if (pos <= mij) return queryVal (f1, st, mij, pos);
    return queryVal (f2, mij + 1, dr, pos);
}

void dfs (int nod)
{
    if (nod == -1) return ;
    if (t[nod] != -1)
        initialValue[nod] = initialValue[t[nod]] + 1;
    dfs (lft[nod]);
    dfs (rgt[nod]);
}

void deletePos (int i)
{
    ///deletes i given it's the leftmost and not the root
    setVal (1, 1, 2 * N, i, 0);
    int f = t[i];
    if (i + 1 <= f - 1)
        update (1, 1, 2 * N, i + 1, f - 1, -1);
    lft[f] = rgt[i], t[rgt[i]] = f;
    t[i] = lft[i] = rgt[i] = -1;
}

void insertPos (int i)
{
    ///inserts i to the right (just after i - 1)
    int q = i - 1;
    if (a[i] > a[q])
    {
        rgt[q] = i, t[i] = q;
        setVal (1, 1, 2 * N, i, queryVal (1, 1, 2 * N, q) + 1);
        return ;
    }
    while (a[i] < a[q])
        q = t[q];
    int son = rgt[q];
    update (1, 1, 2 * N, q + 1, i - 1, +1);
    setVal (1, 1, 2 * N, i, queryVal (1, 1, 2 * N, q) + 1);
    rgt[q] = i, t[i] = q;
    lft[i] = son, t[son] = i;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), a[N + i] = a[i];
for (int i=1; i<=2 * N; i++)
    lft[i] = rgt[i] = t[i] = -1;
for (int i=1; i<=N; i++)
{
    while (nr > 0 && a[stk[nr]] > a[i])
        nr --;
    if (nr == 0)
    {
        t[i] = -1, lft[i] = (i == 1 ? -1 : stk[1]);
        if (lft[i] != -1) t[lft[i]] = i;
    }
    else
    {
        int pos = stk[nr];
        t[i] = pos;
        if (rgt[pos] != -1)
            lft[i] = rgt[pos], t[rgt[pos]] = i, rgt[pos] = i;
        else
            rgt[pos] = i;
    }
    stk[++nr] = i;
}
initialValue[stk[1]] = 1, dfs (stk[1]);
build (1, 1, 2 * N);
int ans = aint[1], how = 0;
for (int k=1; k<N; k++)
{
    ///move a[k] to a[k + N]
    if (a[k] == 1)
    {
        ///this is a special case as all the tree stays the same
        lft[k + N] = rgt[k], rgt[k] = -1, t[lft[k + N]] = k + N;
        setVal (1, 1, 2 * N, k, 0);
        setVal (1, 1, 2 * N, N + k, 1);
        continue;
    }
    deletePos (k);
    insertPos (k + N);
//    fprintf (stderr, "%d -> %d\n", k, aint[1]);
    if (aint[1] < ans)
        ans = aint[1], how = k;
}
printf ("%d %d\n", ans, how);
return 0;
}