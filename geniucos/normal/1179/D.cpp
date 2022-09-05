#include<bits/stdc++.h>

using namespace std;

vector < int > v[500009], sons[500009];
int N, vol[500009], t[500009];
long long ans, dp[500009];

void dfs (int nod)
{
    vol[nod] = 1;
    for (auto it : v[nod])
        if (it != t[nod])
        {
            sons[nod].push_back (it), t[it] = nod;
            dfs (it), vol[nod] += vol[it];
        }
}

long long c2 (int x) {return 1LL * x * (x - 1) / 2;}

bool cmp (int i, int j)
{
    return vol[i] > vol[j];
}

namespace chtTrick {
    int nr;
    pair < int, long long > stk[500009];
    long long frm[500009];
    long long intersect (pair < int, long long > f1, pair < int, long long > f2)
    {
        ///when does f2 become better than f1 (guaranteed f2.first <= f1.first)
        if (f1.first == f2.first)
        {
            if (f1.second < f2.second) return 1LL << 60; ///never
            return -(1LL << 60); ///always
        }
        long long sus = f2.second - f1.second, jos = f1.first - f2.first;
        if (sus % jos == 0) return sus / jos;
        return sus / jos + 1;
    }

    void add (int a, long long b)
    {
        ///add ax + b, a comes in decreasing order
        if (nr > 0 && stk[nr].first == a && stk[nr].second < b) return ;///useless
        pair < int, long long > curr = {a, b};
        while (nr > 0 && intersect (stk[nr], curr) < frm[nr])
            nr --;
        stk[++nr] = curr;
        if (nr > 1) frm[nr] = intersect (stk[nr - 1], stk[nr]);
        else frm[nr] = -(1LL << 60);
    }

    long long minQuery (int x)
    {
        if (nr == 0) return (1LL << 50);
        int p = 1, u = nr, mij, ras = 1;
        while (p <= u)
        {
            mij = (p + u) >> 1;
            if (frm[mij] <= x) ras = mij, p = mij + 1;
            else u = mij - 1;
        }
        return 1LL * stk[ras].first * x + stk[ras].second;
    }
}

void solve (int nod)
{
    dp[nod] = c2 (vol[nod]);
    for (auto it : sons[nod])
    {
        solve (it);
        dp[nod] = min (dp[nod], dp[it] + c2 (vol[nod] - vol[it]));
    }
    {
        ///maybe just a path downwards
        long long curr = 2LL * (dp[nod] + c2 (N - vol[nod]));
        if (curr < ans)
            ans = curr;
    }
    if (sons[nod].size () > 1)
    {
        ///+case when nod = LCA
        sort (sons[nod].begin (), sons[nod].end (), cmp);
        chtTrick::nr = 0;
        for (auto it : sons[nod])
        {
            long long currAdd = 2LL * dp[it] + 1LL * vol[it] * (vol[it] + 1) - 2LL * N * (vol[it]);
            ///update ans by minQuery (vol[it]) + currAdd
            if (chtTrick::nr != 0)
            {
                long long curr = 1LL * N * (N - 1) + chtTrick::minQuery (vol[it]) + currAdd;
                if (curr < ans)
                    ans = curr;
            }
            ///add (2 * vol[it] * x + currAdd)
            chtTrick::add (2 * vol[it], currAdd);
        }
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y),
    v[x].push_back (y),
    v[y].push_back (x);
}
ans = 2LL * N * (N - 1); /// ans will keep twice the minimum
dfs (1);
solve (1);
printf ("%I64d\n", 1LL * N * (N - 1) - ans / 2);
return 0;
}