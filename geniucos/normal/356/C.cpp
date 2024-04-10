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

int N, ap[10], non0, sum;
char sir[2000009];

class flow_network
{
    public:
    int C[10][10], F[10][10], bani[10][10], bst[10], t[10], in_q[10], N, S, D;
    vector < int > v[10];

    void add_edge (int x, int y, int cap, int cst)
    {
        bani[x][y] = cst, C[x][y] = cap;
        bani[y][x] = -cst;
        v[x].push_back (y), v[y].push_back (x);
    }

    void Change_Cap (int x, int y, int new_cap)
    {
        C[x][y] = new_cap;
    }

    bool bellman ()
    {
        queue < int > cc;
        for (int i=1; i<=N; i++)
            bst[i] = 1<<28, t[i] = -1, in_q[i] = 0;

        cc.push (S), bst[S] = 0, in_q[S] = 1;
        while (!cc.empty ())
        {
            int nod = cc.front ();
            in_q[nod] = 0;
            cc.pop ();
            for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
                if (F[nod][*it] < C[nod][*it] && bst[*it] > bst[nod] + bani[nod][*it])
                {
                    bst[*it] = bst[nod] + bani[nod][*it];
                    t[*it] = nod;
                    if (in_q[*it] == 0)
                        in_q[*it] = 1, cc.push (*it);
                }
        }
        return (bst[D] != (1<<28));
    }

    pair < int , int > Min_Cost_Max_Flow ()
    {
        int fl = 0, cst = 0;
        while (bellman ())
        {
            int mini = 1<<28;
            for (int i=D; i != S; i = t[i])
                if (C[t[i]][i] - F[t[i]][i] < mini)
                    mini = C[t[i]][i] - F[t[i]][i];
            fl += mini, cst += mini * bst[D];
            for (int i=D; i != S; i = t[i])
            {
                F[t[i]][i] += mini;
                F[i][t[i]] -= mini;
            }
        }
        return make_pair (fl, cst);
    }

    void Clear_traveled_path ()
    {
        for (int i=1; i<=N; i++)
            for (vector < int > :: iterator it = v[i].begin (); it != v[i].end (); it ++)
                F[i][*it] = 0;
    }

    void Print_Network ()
    {
        for (int i=1; i<=N; i++)
            for (vector < int > :: iterator it = v[i].begin (); it != v[i].end (); it ++)
                if (C[i][*it] > 0)
                    printf ("%d -> %d with cost %d and capacity %d\n", i, *it, bani[i][*it], C[i][*it]);
    }

    void Print_Flow ()
    {
        int sol = 0;
        for (int i=1; i<=N; i++)
            for (vector < int > :: iterator it = v[i].begin (); it != v[i].end (); it ++)
                if (F[i][*it] > 0)
                    printf ("%d -> %d, %d times\n", i, *it, F[i][*it]), sol += F[i][*it] * bani[i][*it];
        //printf ("well the answer is %d stupid bitch", sol);
    }
}retea;

int mod (int x)
{
    if (x < 0) return -x;
    return x;
}

void build_network ()
{
    retea.S = 1, retea.D = 2, retea.N = 9;
    for (int i=1; i<=4; i++)
        retea.add_edge (1, i + 2, ap[i], 0);

    for (int i=1; i<=4; i++)
        for (int j=7; j<=9; j++)
        {
            int C;
            if (j == 7) C = 0;
            else C = j - 5;
            retea.add_edge (i + 2, j, 1<<28, mod (C - i));
        }

    for (int i=7; i<=9; i++)
        retea.add_edge (i, 2, 0, 0);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
gets (sir + 1);
for (int i=1; i<=N; i++)
{
    int ai = (sir[(i<<1) - 1] - '0');
    non0 += (ai != 0);
    ap[ai] ++, sum += ai;
}

build_network ();

int ans = -1;
for (int X = 0; X * 3 <= sum; X ++)
    if ((sum - X * 3) % 4 == 0)
    {
        int a, b, c;
        b = X, c = (sum - X * 3) / 4;
        if (b + c > non0)
            continue;
        a = non0 - b - c;
        retea.Change_Cap (7, 2, a);
        retea.Change_Cap (8, 2, b);
        retea.Change_Cap (9, 2, c);

        pair < int , int > slv = retea.Min_Cost_Max_Flow ();
        retea.Clear_traveled_path ();
        if (slv.first != non0)
            continue;
        if (ans == -1 || ans > slv.second / 2)
            ans = slv.second / 2;
    }

printf("%d\n", ans);

return 0;
}