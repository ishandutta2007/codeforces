#include<bits/stdc++.h>

using namespace std;

int nr, mod, N, M, niv[200009], ap[200009], vol[200009], ma[200009];
char val[200009];
long long ans[200009], mars[200009];
vector < int > v[200009], fii[200009], comp;
vector < pair < int , int > > queries[200009];
int cc[200009], frq[1 << 20];
int nrk = 21, msk[22];

void dfs (int nod)
{
    comp.push_back (nod);
    ap[nod] = 1;
    vol[nod] = 1;
    ma[nod] = 0;
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (ap[*it] == 0)
        {
            dfs (*it);
            vol[nod] += vol[*it];
            if (vol[*it] > ma[nod])
                ma[nod] = vol[*it];
        }
}

void df2 (int nod)
{
    ap[nod] = 1;
    for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
        if (ap[*it] == 0)
        {
            fii[nod].push_back (*it);
            df2 (*it);
        }
}

void solve (int nod)
{
    comp.clear ();
    dfs (nod);
    for (vector < int > :: iterator it = comp.begin (); it != comp.end (); it ++)
        ap[*it] = 0;

    int CG = (*comp.begin ());
    for (vector < int > :: iterator it = comp.begin (); it != comp.end (); it ++)
    {
        if (comp.size () - vol[*it] > ma[*it])
            ma[*it] = comp.size () - vol[*it];
        if (ma[*it] < ma[CG])
            CG = *it;
    }

    df2 (CG);
    for (vector < int > :: iterator it = comp.begin (); it != comp.end (); it ++)
        ap[*it] = 0;

    //////////////////////////////////////////////////////////////////////////////////pot parcurge arborele rutat in CG
    vector < int > cl;
    frq[1 << val[CG]] ++, cl.push_back (1 << val[CG]), ans[CG] ++;///itself
    for (vector < int > :: iterator it_fiu = fii[CG].begin (); it_fiu != fii[CG].end (); it_fiu ++)
    {
        int fiu = *it_fiu; nr = 0;
        cc[++nr] = fiu, niv[fiu] = 1 << val[fiu];
        for (int i=1; i<=nr; i++)
        {
            int curr_nod = cc[i];
            long long curr = 0;
            for (int k=1; k<=nrk; k++)
                curr += frq[ niv[curr_nod] ^ msk[k] ];
            mars[curr_nod] += curr, ans[CG] += curr;
            for (vector < int > :: iterator it = fii[curr_nod].begin (); it != fii[curr_nod].end (); it ++)
                niv[*it] = niv[curr_nod] ^ (1 << val[*it]), cc[++nr] = *it;
        }
        for (int i=nr; i>=1; i--)
            for (auto it : fii[cc[i]])
                mars[cc[i]] += mars[it];
        for (int i=1; i<=nr; i++)
        {
            ans[cc[i]] += mars[cc[i]], mars[cc[i]] = 0;
            if (++frq[niv[cc[i]] ^ (1 << val[CG])] == 1)
                cl.push_back (niv[cc[i]] ^ (1 << val[CG]));
        }
    }
    for (auto it : cl)
        frq[it] = 0;
    cl.clear ();


    for (vector < int > :: reverse_iterator it_fiu = fii[CG].rbegin (); it_fiu != fii[CG].rend (); it_fiu ++)
    {
        int fiu = *it_fiu; nr = 0;
        cc[++nr] = fiu, niv[fiu] = 1 << val[fiu];
        for (int i=1; i<=nr; i++)
        {
            int curr_nod = cc[i];
            long long curr = 0;
            for (int k=1; k<=nrk; k++)
                curr += frq[ niv[curr_nod] ^ msk[k] ];
            mars[curr_nod] += curr;
            for (vector < int > :: iterator it = fii[curr_nod].begin (); it != fii[curr_nod].end (); it ++)
                niv[*it] = niv[curr_nod] ^ (1 << val[*it]), cc[++nr] = *it;
        }
        for (int i=nr; i>=1; i--)
            for (auto it : fii[cc[i]])
                mars[cc[i]] += mars[it];
        for (int i=1; i<=nr; i++)
        {
            ans[cc[i]] += mars[cc[i]], mars[cc[i]] = 0;
            if (++frq[ niv[cc[i]] ^ (1 << val[CG]) ] == 1)
                cl.push_back (niv[cc[i]] ^ (1 << val[CG]));
        }
    }
    for (auto it : cl)
        frq[it] = 0;
    cl.clear ();


    for (vector < int > :: iterator it = comp.begin (); it != comp.end (); it ++)
        fii[*it].clear ();
    //////////////////////////////////////////////////////////////////////////////////

    ap[CG] = 2;
    for (vector < int > :: iterator it = v[CG].begin (); it != v[CG].end (); it ++)
        if (ap[*it] == 0)
            solve (*it);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

for (int i=0; i<20; i++)
    msk[i + 1] = 1 << i;

scanf ("%d", &N);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d\n", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
gets (val + 1);
for (int i=1; i<=N; i++)
    val[i] -= 'a';
solve (1);
for (int i=1; i<=N; i++)
    printf ("%I64d%c", ans[i], " \n"[i == N]);
return 0;
}