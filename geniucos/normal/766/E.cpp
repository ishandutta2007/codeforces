#include<bits/stdc++.h>

using namespace std;

int cnt[30][2], N, b[100009], a[100009], P[100009], vol[100009];
long long currAns, ans;
vector < int > v[100009];

void dfs (int nod, int tata)
{
    vol[nod] = 1, P[nod] = -1;
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
    if (*it != tata)
    {
        dfs (*it, nod), vol[*it] += vol[nod];
        if (P[nod] == -1 || vol[*it] > vol[P[nod]]) P[nod] = *it;
    }
}

void solve (int nod, int tata, int lev)
{
    currAns += b[nod];
    if (P[nod] == -1)
    {
        cnt[lev][0] = cnt[lev][1] = 0;
        cnt[lev][b[nod]] ++;
        return ;
    }
    solve (P[nod], nod, lev);
    currAns += cnt[lev][b[nod] ^ 1];
    for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
        if (*it != P[nod] && *it != tata)
        {
            solve (*it, nod, lev + 1);
            currAns += cnt[lev + 1][b[nod] ^ 1];
            currAns += 1LL * cnt[lev][1] * cnt[lev + 1][b[nod]] + 1LL * cnt[lev][0] * cnt[lev + 1][b[nod] ^ 1];
            cnt[lev][0] += cnt[lev + 1][0], cnt[lev][1] += cnt[lev + 1][1];
            cnt[lev + 1][0] = cnt[lev + 1][1] = 0;
        }
    if (b[nod]) swap (cnt[lev][0], cnt[lev][1]);
    cnt[lev][b[nod]] ++;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
dfs (1, -1);
for (int bit = 0; (1 << bit) <= 1000000; bit ++)
{
    for (int i=1; i<=N; i++)
        b[i] = (a[i] >> bit) & 1;
    currAns = 0, solve (1, -1, 0);
//    printf ("%d -> %I64d\n", bit, currAns);
    ans += 1LL * currAns * (1 << bit);
}
printf ("%I64d\n", ans);

return 0;
}