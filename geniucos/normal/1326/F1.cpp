#include<bits/stdc++.h>

using namespace std;

int N, a[20], nodes, e[500], t[500], h[500], son[500][20], spec[20], nrb[1 << 18];
char adj[20][20];
long long cnt[500], c[20][20], fac[20], dp[1 << 18][18], ans[1 << 18];
vector < int > v[1 << 18];

void back (int pos, int sum, int currNode)
{
    /*printf ("%d:", currNode);
    for (int i=1; i<pos; i++)
        printf (" %d", a[i]);
    printf ("\n");*/
    if (pos > 1)
    {
        int currS = 0;
        for (int i=1; i<=N; i++)
            spec[i] = 0;
        for (int i=1; i<pos; i++)
            spec[currS + 1] = 1,
            currS += a[i];
        for (int msk = 0; msk < (1 << N); msk ++)
            if (nrb[msk] <= currS)
                for (auto i : v[msk])
                {
                    if (msk == (1 << i))
                        dp[msk][i] = 1;
                    if (dp[msk][i] == 0)
                        continue;
                    if (nrb[msk] == currS)
                        cnt[nodes] += dp[msk][i];
                    else
                    {
                        for (auto j : v[((1 << N) - 1) ^ msk])
                            if (adj[i][j] || spec[nrb[msk] + 1])
                                dp[msk | (1 << j)][j] += dp[msk][i];
                    }
                    dp[msk][i] = 0; ///end of job clear
                }
        cnt[nodes] *= fac[N - currS];
    }
    for (int i=a[pos - 1] + 2 * (pos == 1); i + sum <= N; i++)
    {
        a[pos] = i;
        nodes ++;
        t[nodes] = currNode;
        e[nodes] = i, son[currNode][i] = nodes;
        h[nodes] = h[currNode] + i;
        back (pos + 1, sum + i, nodes);
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
for (int i=0; i<N; i++)
{
    scanf ("%s", adj[i]);
    for (int j=0; j<N; j++)
        adj[i][j] -= '0';
}
fac[0] = 1;
for (int i=1; i<=N; i++)
    fac[i] = 1LL * fac[i - 1] * i;
c[0][0] = 1;
for (int i=1; i<=N; i++)
{
    c[i][0] = 1;
    for (int j=1; j<=i; j++)
        c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
}
for (int msk = 1; msk < (1 << N); msk ++)
{
    for (int j=0; j<N; j++)
        if (msk & (1 << j))
            v[msk].push_back (j);
    nrb[msk] = v[msk].size ();
}
nodes = 1, back (1, 0, 1);
cnt[1] = fac[N];
N --;
for (int msk = (1 << N) - 1; msk >= 0; msk --)
{
    int lst = -2, curr = 0;
    vector < int > v;
    for (int i=0; i<N; i++)
        if (msk & (1 << i))
        {
            if (lst == i - 1)
                curr ++;
            else
            {
                if (curr > 0)
                    v.push_back (curr + 1);
                curr = 1;
            }
            lst = i;
        }
    if (curr > 0)
        v.push_back (curr + 1);
    sort (v.begin (), v.end ());
    int q = 1;
    for (auto it : v)
        q = son[q][it];
    ans[msk] = cnt[q];
    for (int msk2 = (msk + 1) | msk; msk2 < (1 << N); msk2 = (msk2 + 1) | msk)
        ans[msk] -= ans[msk2];
}
for (int i=0; i<(1 << N); i++)
    printf ("%I64d%c", ans[i], " \n"[i == (1 << N) - 1]);
return 0;
}