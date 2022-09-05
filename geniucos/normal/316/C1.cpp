#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<algorithm>

using namespace std;

int nr, N, M, a[89][89], cod[89][89], b[89][89];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

class MaxFlowMinCost
{
    public:
    int N, M, S, D, ap[1009], t[1009], bell[1009], in_q[1009], F[1009][1009], C[1009][1009], bani[1009][1009];
    vector < int > v[1009];

    bool bellman ()
    {
        queue < int > cc;
        for (int i=1; i<=N; i++)
            t[i] = -1, bell[i] = 1<<30, in_q[i] = 0;
        t[S] = 0, in_q[S] = 1, bell[S] = 0;
        cc.push (S);
        while (!cc.empty ())
        {
            int nod = cc.front ();
            cc.pop ();
            in_q[nod] = 0;
            for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
                if (bell[*it] > bell[nod] + bani[nod][*it] && C[nod][*it] > F[nod][*it])
                {
                    bell[*it] = bell[nod] + bani[nod][*it];
                    t[*it] = nod;
                    if (in_q[*it] == 0)
                    {
                        in_q[*it] = 1;
                        cc.push (*it);
                    }
                }
        }
        return (bell[D] < (1<<30));
    }

    void add_edge (int x, int y, int cap, int ban)
    {
        C[x][y] = cap;
        v[x].push_back (y), v[y].push_back (x);
        bani[x][y] = ban, bani[y][x] = -ban;
    }

    int compute_flow ()
    {
        int cost = 0, tot_fl = 0;
        while (bellman ())
        {
            int mini = 1<<30;
            for (int i=D; i != S; i = t[i])
                if (C[t[i]][i] - F[t[i]][i] < mini)
                    mini = C[t[i]][i] - F[t[i]][i];
            cost += mini * bell[D];
            tot_fl += mini;
            for (int i=D; i != S; i = t[i])
            {
                F[t[i]][i] += mini;
                F[i][t[i]] -= mini;
            }
        }
        //printf ("fluxu e %d\n", tot_fl);
        return cost;
    }
}flow_network;

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
flow_network.S = 1, flow_network.D = flow_network.N = 2;
for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
        scanf ("%d", &a[i][j]), cod[i][j] = ++flow_network.N;

for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
    {
        if ((i + j) & 1)
        {
            flow_network.add_edge (flow_network.S, cod[i][j], 1, 0);
            for (int k=0; k<4; k++)
                if (cod[i+dx[k]][j+dy[k]])
                    flow_network.add_edge (cod[i][j], cod[i+dx[k]][j+dy[k]], 1, (a[i][j] != a[i+dx[k]][j+dy[k]]));
        }
        else flow_network.add_edge (cod[i][j], flow_network.D, 1, 0);
    }

printf ("%d\n", flow_network.compute_flow () );

/*if ()
{
    int nr = 0;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            if ((i + j) & 1)
            {
                for (int k=0; k<4; k++)
                    if (flow_network.F[cod[i][j]][cod[i+dx[k]][j+dy[k]]] == 1)
                        b[i][j] = b[i+dx[k]][j+dy[k]] = ++nr;
            }
    for (int i=1; i<=N; i++, printf ("\n"))
        for (int j=1; j<=M; j++)
            printf ("%2d ", b[i][j]);
}*/
return 0;
}