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

int N, M, X[200109], dp[200109];
int arb[2][800109], ans;
priority_queue < pair < int , int > , vector < pair < int , int > > , greater < pair < int , int > > > v;

void Update (int lin, int nod, int st, int dr, int pos, int val)
{
    if (st == dr)
    {
        arb[lin][nod] = val;
        return ;
    }
    int mij = (st + dr) >> 1;
    if (pos <= mij) Update (lin, nod<<1, st, mij, pos, val);
    else Update (lin, (nod<<1) + 1, mij + 1, dr, pos, val);
    arb[lin][nod] = max (arb[lin][nod<<1], arb[lin][(nod<<1) + 1]);
}

void Query (int lin, int nod, int st, int dr, int x, int y)
{
    if (x <= st && dr <= y)
    {
        if (arb[lin][nod] > ans)
            ans = arb[lin][nod];
        return ;
    }
    int mij = (st + dr) >> 1;
    if (x <= mij) Query (lin, nod<<1, st, mij, x, y);
    if (y > mij) Query (lin, (nod<<1) + 1, mij + 1, dr, x, y);
}

void add (int x, int h)
{
    vector < pair < int , int > > low_pos;
    for (int i = max (h - 10, 0); i < h; i ++)
        if (X[i] != 0)
        {
            Update (0, 1, 1, N, X[i], 0);
            low_pos.push_back (make_pair (X[i], i));
        }
    X[h] = x;
    low_pos.push_back (make_pair (x, h));
    v.push (make_pair (x, h));
    for (vector < pair < int , int > > :: reverse_iterator it = low_pos.rbegin (); it != low_pos.rend (); it ++)
    {
        ans = 0, Query (0, 1, 1, N, it->first + 1, N);
        dp[it->first] = ans + 1, Update (0, 1, 1, N, it->first, dp[it->first]), Update (1, 1, 1, M + 12, it->second, dp[it->first]);
    }
}

void del (int x)
{
    vector < pair < int , int > > left_pos;
    for (int i=1; i<=x; i++)
    {
        pair < int , int > curr = v.top ();
        v.pop ();
        if (i < x) left_pos.push_back (curr);
        else X[curr.second] = 0, Update (0, 1, 1, N, curr.first, 0);
        Update (1, 1, 1, M + 12, curr.second, 0);
    }
    for (vector < pair < int , int > > :: reverse_iterator it = left_pos.rbegin (); it != left_pos.rend (); it ++)
    {
        ans = 0, Query (1, 1, 1, M + 12, it->second + 1, M + 12);
        dp[it->first] = ans + 1, Update (1, 1, 1, M + 12, it->second, dp[it->first]), Update (0, 1, 1, N, it->first, dp[it->first]), v.push (*it);
    }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int etapa = 1; etapa <= M; etapa ++)
{
    int tip;
    scanf ("%d", &tip);
    if (tip == 1)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        y += M - etapa;
        //printf ("operatia: %d %d\n", x, y);
        add (x, y);
    }
    else
    {
        int x;
        scanf ("%d", &x);
        del (x);
    }
    printf ("%d\n", arb[1][1]);
}

return 0;
}