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
    int N, M, S, D, ap[7009], t[7009], bell[7009], in_q[7009];
    int C_F[60009], bani[60009], Y[60009];
    vector < int > v[7009];

    void add_edge (int x, int y, int cap, int ban)
    {
        Y[++M] = y, v[x].push_back (M), bani[M] = ban, C_F[M] = cap;
        Y[++M] = x, v[y].push_back (M), bani[M] = -ban, C_F[M] = 0;
    }

    int opus (int edge)
    {
        if (edge & 1) return edge + 1;
        return edge - 1;
    }

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
                if (bell[Y[*it]] > bell[nod] + bani[*it] && C_F[*it] > 0)
                {
                    bell[Y[*it]] = bell[nod] + bani[*it];
                    t[Y[*it]] = *it;
                    if (in_q[Y[*it]] == 0)
                    {
                        in_q[Y[*it]] = 1;
                        cc.push (Y[*it]);
                    }
                }
        }
        return (bell[D] < (1<<30));
    }

    int compute_flow ()
    {
        int cost = 0, tot_fl = 0;
        while (bellman ())
        {
            int mini = 1<<30;
            for (int i=D; i != S; i = Y[opus (t[i])])
                if (C_F[t[i]] < mini)
                    mini = C_F[t[i]];
            cost += mini * bell[D];
            tot_fl += mini;
            for (int i=D; i != S; i = Y[opus (t[i])])
            {
                C_F[t[i]] -= mini;
                C_F[opus (t[i])] += mini;
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