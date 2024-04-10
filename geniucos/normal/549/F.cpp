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

int N, K, A[300009], S[300009], ap[1000009];
pair < int, int > arb[1200009], ans;
vector < pair < int , bool > > v[300009];

void add_query (int st, int dr, int val)
{
    if (st > dr) return ;
    v[dr].push_back (make_pair (val, 1));
    v[st - 1].push_back (make_pair (val, 0));
}

void build (int nod, int st, int dr)
{
    if (st == dr) {arb[nod] = make_pair (A[st], st);return ;}
    int mij = (st + dr) >> 1;
    build (nod<<1, st, mij);
    build ((nod<<1) + 1, mij + 1, dr);
    arb[nod] = max (arb[nod << 1], arb[(nod << 1) + 1]);
}

void Query (int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
    {
        if (x == st) ans = arb[nod];
        else ans = max (ans, arb[nod]);
        return ;
    }
    int mij = (st + dr) >> 1;
    if (x <= mij) Query (nod << 1, st, mij, x, y);
    if (y > mij) Query ((nod << 1) + 1, mij + 1, dr, x, y);
}

int biggest (int Left, int Right)
{
    Query (1, 1, N, Left, Right);
    return ans.second;
}

void solve (int st, int dr)
{
    if (st >= dr) return ;
    int pos = biggest (st, dr);
    if (dr - pos < pos - st)
    {
        ////S[j] - S[i - 1] - A[pos] = 0 mod K
        ////S[j] - A[pos] = S[i - 1]
        for (int j=pos + 1; j<=dr; j++)
        {
            int val = S[j] - A[pos];
            if (val < 0) val += K;
            add_query (st - 1, pos - 2, val);
        }
    }
    else
    {
        ////S[j] - S[i - 1] - A[pos] = 0 mod K
        ////S[j] = S[i - 1] + A[pos]
        for (int i=st; i<pos; i++)
        {
            int val = S[i - 1] + A[pos];
            if (val >= K) val -= K;
            add_query (pos + 1, dr, val);
        }
    }

    /////S[i] - S[pos] = 0 [pos, i], pos < i <= dr
    add_query (pos + 1, dr, S[pos]);
    solve (pos + 1, dr);

    /////S[pos - 1] - S[i - 1] = 0 [i, pos], st <= i < pos -> st - 1 <= i - 1 < pos - 1
    add_query (st - 1, pos - 2, S[pos - 1]);
    solve (st, pos - 1);
}

void Read (int &x);

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

Read (N), Read (K);
for (int i=1; i<=N; i++)
    Read (A[i]);
build (1, 1, N);
for (int i=1; i<=N; i++)
{
    A[i] %= K;
    S[i] = S[i-1] + A[i];
    if (S[i] >= K) S[i] -= K;
}

solve (1, N);

long long ans = 0;
for (int i=0; i<=N; i++)
{
    ap[S[i]] ++;
    for (vector < pair < int , bool > > :: iterator it = v[i].begin (); it != v[i].end (); it ++)
    {
        if (it -> second == 0) ans -= ap[it -> first];
        else ans += ap[it -> first];
    }
}
printf ("%I64d\n", ans);

return 0;
}

#define maxl 100000
int pos = maxl - 1;
char sir[maxl];

void Next ()
{
    if (++pos == maxl)
        fread (sir, 1, maxl, stdin), pos = 0;
}

void Read (int &x)
{
    for (; sir[pos] < '0' || sir[pos] > '9'; Next ()) ;
    for (x = 0; sir[pos] >= '0' && sir[pos] <= '9'; Next ()) x = x * 10 + sir[pos] - '0';
}