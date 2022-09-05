#include<bits/stdc++.h>

using namespace std;

int D, N, M, E, lft[100009], rgt[100009], ans[100009], cntL[1017], cntR[1017], negL[1017][1017], negR[1017][1017];
map < pair < int, int >, int > mp;

bool ap[2][2017];
vector < pair < int, int > > traversedEdges, traversedNodes;
void free (bool side, int node, int c1, int c2)
{
    if (ap[side][node]) return ;
    ap[side][node] = 1;
    traversedNodes.push_back ({side, node});
    if (side == 1)
    {
        if (negR[node][c1] == 0) return ;
        traversedEdges.push_back ({negR[node][c1], node});
        free (0, negR[node][c1], c1, c2);
    }
    else
    {
        if (negL[node][c2] == 0) return ;
        traversedEdges.push_back ({node, negL[node][c2]});
        free (1, negL[node][c2], c1, c2);
    }
}

void setEdge (int x, int y, int c)
{
    negL[x][c] = y;
    negR[y][c] = x;
}

void delEdge (int x, int y, int c) {negL[x][c] = negR[y][c] = 0;}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &M, &E);
for (int i=1; i<=E; i++)
    scanf ("%d %d", &lft[i], &rgt[i]), cntL[lft[i]] ++, cntR[rgt[i]] ++, mp[{lft[i], rgt[i]}] = i;
for (int i=1; i<=N; i++)
    if (cntL[i] > D)
        D = cntL[i];
for (int i=1; i<=M; i++)
    if (cntR[i] > D)
        D = cntR[i];
for (int currStep = 1; currStep <= E; currStep ++)
{
    int x = lft[currStep], y = rgt[currStep];
    bool ok = 0;
    for (int i=1; i<=D; i++)
        if (negL[x][i] == 0 && negR[y][i] == 0)
        {
            setEdge (x, y, i);
            ok = 1;
            break;
        }
    if (ok) continue;
    int c1 = -1, c2 = -1;
    for (int i=1; i<=D; i++)
        if (negL[x][i] == 0)
        {
            c1 = i;
            break;
        }
    for (int i=1; i<=D; i++)
        if (negR[y][i] == 0)
        {
            c2 = i;
            break;
        }
    traversedEdges.clear (), traversedNodes.clear ();
    free (1, y, c1, c2);
    bool type = 1;
    for (auto it : traversedEdges)
    {
        if (type) delEdge (it.first, it.second, c1);
        else delEdge (it.first, it.second, c2);
        type ^= 1;
    }
    type = 1;
    for (auto it : traversedEdges)
    {
        if (type) setEdge (it.first, it.second, c2);
        else setEdge (it.first, it.second, c1);
        type ^= 1;
    }
    for (auto it : traversedNodes)
        ap[it.first][it.second] = 0;
    setEdge (x, y, c1);
}
printf ("%d\n", D);
for (int i=1; i<=N; i++)
    for (int j=1; j<=D; j++)
        if (negL[i][j] != 0)
            ans[mp[{i, negL[i][j]}]] = j;
for (int i=1; i<=E; i++)
    printf ("%d%c", ans[i], " \n"[i == E]);
return 0;
}