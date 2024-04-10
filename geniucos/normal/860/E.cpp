#include<bits/stdc++.h>

using namespace std;

int root, N, nr, nr2, t[500009], v[500009], ap[500009], ap2[500009], stk[500009], st[500009], dr[500009], pos[500009], niv[500009], lst[500009], vol[500009], Q[1000009], rmq[21][1000009], lg[1000009];
long long ans[500009], mars[500009];
vector < int > h[500009], ed[500009], onLev[500009];
#define bst(a, b) ((niv[a] > niv[b])?b:a)

void df_init (int nod)
{
    pos[nod] = ++nr, Q[nr] = nod, st[nod] = ++nr2;
    for (vector < int > :: iterator it = ed[nod].begin (); it != ed[nod].end (); it ++)
        niv[*it] = niv[nod] + 1, df_init (*it), Q[++nr] = nod, lst[nod] = nr;
    dr[nod] = nr2, onLev[niv[nod]].push_back (nod);
}

void BuildRmq ()
{
    for (int i=1; i<=nr; i++)
        rmq[0][i] = Q[i];
    for (int i=2; i<=nr; i++)
        lg[i] = lg[i >> 1] + 1;
    for (int i=1; (1<<i)<=nr; i++)
        for (int j=1; j + (1 << i)<=nr; j++)
            rmq[i][j] = bst (rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
}

int LCA (int nod1, int nod2)
{
    int st = pos[nod1], dr = pos[nod2];
    if (st > dr) swap (st, dr);
    int k = lg[dr - st + 1];
    return bst (rmq[k][st], rmq[k][dr - (1 << k) + 1]);
}

struct cmp {
    bool operator () (const int &x, const int &y) const {
        return pos[x] < pos[y];
    }
};

void dfs (int nod)
{
    vol[nod] = ap[nod];
    for (auto it : h[nod])
        dfs (it), vol[nod] += vol[it];
}

void push (int nod)
{
    for (auto it : h[nod])
        mars[it] += mars[nod] + 1LL * vol[it] * (niv[it] - niv[nod] - 1) + vol[nod], push (it);
//        mars[it] += mars[nod] + 1LL * vol[nod] * (niv[it] - niv[nod]), push (it);
}

void Read (int &x);
int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

Read (N);
int bigRoot;
for (int i=1; i<=N; i++)
{
    Read (t[i]);
    if (t[i] == 0) bigRoot = i;
    else ed[t[i]].push_back (i);
}
df_init (bigRoot), BuildRmq ();
for (int lv = 1; !onLev[lv].empty (); lv++)
{
    int l = onLev[lv].size (), l2 = l;
    for (int i=1; i<=l; i++)
        v[i] = onLev[lv][i - 1], ap[v[i]] = ap2[v[i]] = 1;
    sort (v + 1, v + l + 1, cmp ());
    for (int i=2; i<=l; i++)
    {
        int curr = LCA (v[i - 1], v[i]);
        if (!ap2[curr]) ap2[curr] = 1, v[++l2] = curr;
    }
    if (ap2[bigRoot] == 0)
        ap2[bigRoot] = 1, v[++l2] = bigRoot;
    sort (v + 1, v + l2 + 1, cmp ()), nr = 0;
    for (int i=1; i<=l2; i++)
    {
        while (nr && lst[stk[nr]] < pos[v[i]]) nr --;
        if (nr == 0) root = v[i];
        else h[stk[nr]].push_back (v[i]);
        stk[++nr] = v[i];
    }
    dfs (root), push (root);
    for (int i=1; i<=l2; i++)
        if (ap[v[i]])
            ans[v[i]] = ans[t[v[i]]] + mars[v[i]];
    for (int i=1; i<=l2; i++)
    {
        h[v[i]].clear ();
        ap2[v[i]] = ap[v[i]] = 0, mars[v[i]] = 0;
    }
}
for (int i=1; i<=N; i++)
    printf ("%I64d%c", ans[i], " \n"[i == N]);
return 0;
}

#define maxl 100000
int Pos = maxl - 1;
char sir[maxl];

void Next ()
{
    if (++Pos == maxl)
        fread (sir, 1, maxl, stdin), Pos = 0;
}

void Read (int &x)
{
    while (sir[Pos] < '0' || sir[Pos] > '9') Next ();
    for (x = 0; sir[Pos] >= '0' && sir[Pos] <= '9'; Next ()) x = x * 10 + sir[Pos] - '0';
}