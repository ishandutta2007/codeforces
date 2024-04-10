#include<bits/stdc++.h>

using namespace std;

//const int NMAX = 100;
const int NMAX = 350009;

int Q, N, currentS[NMAX], s[NMAX], t[NMAX], l[NMAX], r[NMAX], v[NMAX], type[NMAX];
vector < int > ts;
map < int, int > inverseT;

void read ()
{
    scanf ("%d", &Q);
    for (int i=1; i<=Q; i++)
    {
        scanf ("%d", &type[i]);
        if (type[i] == 1) scanf ("%d %d", &t[i], &s[i]), ts.push_back (t[i]);
        else
        if (type[i] == 2) scanf ("%d", &t[i]);
        else
        {
            scanf ("%d %d %d", &l[i], &r[i], &v[i]);
            ts.push_back (l[i]), ts.push_back (r[i]);
        }
    }
    sort (ts.begin (), ts.end ());
    ts.erase (unique (ts.begin (), ts.end ()), ts.end ()), N = ts.size ();
/*    for (auto it : ts)
        printf ("%d\n", it);*/
    for (int i=0; i<N; i++)
        inverseT[ts[i]] = i + 1;
    int lastVal = ts[N - 1];
    ts.push_back (lastVal);
    for (int i=1; i<=Q; i++)
        if (type[i] <= 2) t[i] = inverseT[t[i]];
        else l[i] = inverseT[l[i]], r[i] = inverseT[r[i]];
}

set < int > currTimes;
long long sum[4 * NMAX], mi[4 * NMAX];
int vl[4 * NMAX];
bool lzy[4 * NMAX];

int getLength (int x, int y) {return ts[y] - ts[x - 1];}

void split (int nod, int st, int mij, int dr, int f1, int f2)
{
    if (lzy[nod] == 0) return ;
    lzy[f1] = lzy[f2] = 1;
    vl[f1] = vl[f2] = vl[nod];
    sum[f1] = 1LL * vl[nod] * getLength (st, mij);
    mi[f1] = min (0LL, sum[f1]);
    sum[f2] = 1LL * vl[nod] * getLength (mij + 1, dr);
    mi[f2] = min (0LL, sum[f2]);
    lzy[nod] = 0;
}

void setValue (int nod, int st, int dr, int x, int y, int s)
{
/*    if (nod == 1)
        printf ("set %d [%d, %d]\n", s, x, y);*/
    if (x <= st && dr <= y)
    {
        vl[nod] = s, lzy[nod] = 1;
        sum[nod] = 1LL * s * getLength (st, dr);
        mi[nod] = min (0LL, sum[nod]);
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    split (nod, st, mij, dr, f1, f2);
    if (x <= mij) setValue (f1, st, mij, x, y, s);
    if (mij < y) setValue (f2, mij + 1, dr, x, y, s);
    sum[nod] = sum[f1] + sum[f2];
    mi[nod] = min (mi[f1], sum[f1] + mi[f2]);
}

long double ansQ = -1.0;
long long curr;
void query (int nod, int st, int dr, int x, int y)
{
    if (ansQ > -0.5)
        return ;
    if (x <= st && dr <= y)
    {
        int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
        if (st == dr)
        {
            if (mi[nod] + curr > 0)
            {
                curr += sum[nod];
                return ;
            }
            int t1 = ts[st - 1], t2 = ts[st];
            ansQ = t1 + 1.0 * curr / (-vl[nod]);
            return ;
        }
        split (nod, st, mij, dr, f1, f2);
        if (curr + mi[f1] <= 0)
            query (f1, st, mij, x, y);
        else
        if (curr + sum[f1] + mi[f2] <= 0)
            curr += sum[f1], query (f2, mij + 1, dr, x, y);
        else curr += sum[nod];
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    split (nod, st, mij, dr, f1, f2);
    if (x <= mij) query (f1, st, mij, x, y);
    if (mij < y) query (f2, mij + 1, dr, x, y);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

read ();
for (int i=1; i<=Q; i++)
{
    if (type[i] == 1)
    {
        currTimes.insert (t[i]);
        auto it = currTimes.find (t[i]); it ++;
        int rgt = N;
        if (it != currTimes.end ()) rgt = (*it) - 1;
        setValue (1, 1, N, t[i], rgt, s[i]);
        currentS[t[i]] = s[i];
        continue;
    }
    if (type[i] == 2)
    {
        auto it = currTimes.find (t[i]);
        int s = 0;
        if (it != currTimes.begin ())
        {
            auto it2 = it;
            it2 --; s = currentS[*it2];
        }
        it ++;
        int rgt = N;
        if (it != currTimes.end ()) rgt = (*it) - 1;
        setValue (1, 1, N, t[i], rgt, s);
        currTimes.erase (t[i]), currentS[t[i]] = 0;
        continue;
    }
    ansQ = -1.0;
    if (v[i] == 0)
    {
        printf ("%d\n", ts[l[i] - 1]);
        continue;
    }
    if (l[i] != r[i])
    {
        auto it = currTimes.lower_bound (l[i]);
        if (it != currTimes.end () && (*it) < r[i])
            curr = v[i], query (1, 1, N, *it, r[i] - 1);
    }
    cout << setprecision (15) << ansQ << '\n';
}
return 0;
}