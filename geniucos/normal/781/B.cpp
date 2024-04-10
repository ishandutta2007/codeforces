#include<bits/stdc++.h>

using namespace std;

int nr, N, ans[2017], x[2017], y[2017];
bool Fixed[2017], taken[2017];
char a[30], b[30];
map < string, int > mp;
string val[2017];

int getVal (string s)
{
    if (mp.count (s)) return mp[s];
    val[++nr] = s, mp[s] = nr;
    return nr;
}

int st[2017], dr[2017], C[2017];
vector < int > v[2017];
bool cupl (int nod)
{
    if (C[nod]) return 0;
    C[nod] = 1;
    for (auto it = v[nod].begin(); it != v[nod].end(); it ++)
        if (st[*it] == 0)
        {
            st[*it] = nod;
            dr[nod] = *it;
            return 1;
        }
    for (auto it = v[nod].begin(); it != v[nod].end(); it ++)
        if (st[*it] != 0 && cupl (st[*it]))
        {
            st[*it] = nod;
            dr[nod] = *it;
            return 1;
        }
    return 0;
}

int maxMatch ()
{
    int cup = 1;
    while (cup)
    {
        cup = 0;
        for (int i=1; i<=N; i++)
            C[i] = 0;
        for (int i=1; i<=N; i++)
            if (dr[i] == 0) cup += cupl (i);
    }
    cup = 0;
    for (int i=1; i<=N; i++)
        if (dr[i]) cup ++;
    return cup;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
for (int i=1; i<=N; i++)
{
    scanf ("%s %s", a + 1, b + 1);
    string s1, s2;
    s1 += a[1], s1 += a[2], s1 += a[3];
    s2 += a[1], s2 += a[2], s2 += b[1];
    x[i] = getVal (s1), y[i] = getVal (s2);
}
for (int i=1; i<=N; i++)
    if (!Fixed[i])
    {
        int ap = 0;
        for (int j=1; j<=N; j++)
            if (Fixed[j] == 0 && x[j] == x[i]) ap ++;
        if (ap == 1) continue;
        if (ap > 1)
        {
            for (int j=1; j<=N; j++)
                if (Fixed[j] == 0 && x[j] == x[i])
                    Fixed[j] = 1, ans[j] = y[j], taken[y[j]] = 1;
        }
    }
int cnt = 0;
for (int i=1; i<=N; i++)
    if (!Fixed[i])
    {
        cnt ++;
        if (!taken[x[i]]) v[i].push_back (x[i]);
        if (!taken[y[i]]) v[i].push_back (y[i]);
    }
if (maxMatch () != cnt)
{
    printf ("NO\n");
    exit (0);
}
for (int i=1; i<=N; i++)
    if (!Fixed[i])
        ans[i] = dr[i];
for (int i=1; i<=N; i++)
    for (int j=i + 1; j<=N; j++)
        if (ans[i] == ans[j])
        {
            printf ("NO\n");
            return 0;
        }
printf ("YES\n");
for (int i=1; i<=N; i++)
    printf ("%s\n", val[ans[i]].c_str ());
return 0;
}