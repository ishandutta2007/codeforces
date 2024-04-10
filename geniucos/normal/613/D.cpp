#include<iomanip>
#include<iostream>
#include<cstdio>
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

int root, l, l2, nr, N, Qs, dp[100009][2], ap[100009], ap2[100009], st[100009], pos[100009], lst[100009], v[100009], niv[100009], Q[200009], t[100009], rmq[19][200009], lg[200009];
vector < int > h[100009], ed[100009];

void dfs (int nod, int tata)
{
    pos[nod] = ++nr, Q[nr] = nod;
    for (vector < int > :: iterator it = ed[nod].begin (); it != ed[nod].end (); it ++)
        if (*it != tata)
            niv[*it] = niv[nod] + 1, t[*it] = nod, dfs (*it, nod), Q[++nr] = nod, lst[nod] = nr;
}

int bst (int nod1, int nod2)
{
    if (niv[nod1] > niv[nod2]) return nod2;
    return nod1;
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

void solve (int nod)
{
    for (vector < int > :: iterator it = h[nod].begin (); it != h[nod].end (); it ++)
        solve (*it);
    if (ap[nod])
    {
        dp[nod][0] = N + 5, dp[nod][1] = 0;
        for (vector < int > :: iterator it = h[nod].begin (); it != h[nod].end (); it ++)
            dp[nod][1] += dp[*it][0];
    }
    else
    {
        int sum0 = 0, sum1 = 0, maxi = 0;
        for (vector < int > :: iterator it = h[nod].begin (); it != h[nod].end (); it ++)
            sum0 += dp[*it][0], sum1 += min (dp[*it][1], dp[*it][0]), maxi = max (maxi, dp[*it][0] - dp[*it][1]);
        dp[nod][0] = min (sum0, 1 + sum1);
        dp[nod][1] = sum0 - maxi;
    }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    ed[x].push_back (y);
    ed[y].push_back (x);
}
dfs (1, -1), BuildRmq ();
scanf ("%d", &Qs);
while (Qs --)
{
    scanf ("%d", &l), l2 = l;
    for (int i=1; i<=l; i++)
        scanf ("%d", &v[i]), ap[v[i]] = ap2[v[i]] = 1;
    bool oke = 1;
    for (int i=1; i<=l; i++)
        if (ap[t[v[i]]]) oke = 0;
    if (!oke)
    {
        printf ("-1\n");
        for (int i=1; i<=l; i++)
            ap[v[i]] = ap2[v[i]] = 0;
        continue;
    }
    sort (v + 1, v + l + 1, cmp ());
    for (int i=2; i<=l; i++)
    {
        int curr = LCA (v[i - 1], v[i]);
        if (!ap2[curr]) ap2[curr] = 1, v[++l2] = curr;
    }
    for (int i=1; i<=l; i++)
        if ((!ap2[t[v[i]]]) && v[i] != 1) v[++l2] = t[v[i]], ap2[t[v[i]]] = 1;
    sort (v + 1, v + l2 + 1, cmp ()), nr = 0;
    for (int i=1; i<=l2; i++)
    {
        while (nr && lst[st[nr]] < pos[v[i]]) nr --;
        if (nr == 0) root = v[i];
        else h[st[nr]].push_back (v[i]);
        st[++nr] = v[i];
    }
    solve (root);
    printf ("%d\n", min (dp[root][0], dp[root][1]));
    for (int i=1; i<=l2; i++)
    {
        h[v[i]].clear ();
        ap2[v[i]] = ap[v[i]] = 0;
    }
}
return 0;
}