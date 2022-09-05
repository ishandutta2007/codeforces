#include<bits/stdc++.h>

using namespace std;

int N, M, name[216], t[216], cf[216][216], x[1016], y[1016], z[1016];
bool in_mul[216];
vector < int > v[216];
vector < pair < int, int > > h[216];

void add_edge (int x, int y, int z)
{
    if (cf[x][y] == 0) v[x].push_back (y), v[y].push_back (x);
    cf[x][y] += z, cf[y][x] += z;
}

bool bfs (int N, int S, int D)
{
    queue < int > cc;
    for (int i=1; i<=N; i++)
        t[i] = -1;
    t[S] = 0, cc.push (S);
    while (!cc.empty ())
    {
        int nod = cc.front ();
        cc.pop ();
        for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
            if (cf[nod][*it] > 0 && t[*it] == -1)
            {
                t[*it] = nod, cc.push (*it);
                if (*it == D) return 1;
            }
    }
    return 0;
}

int max_flow (int N, int S, int D)
{
    int flow = 0;
    while (bfs (N, S, D))
    {
        for (vector < int > :: iterator it = v[D].begin (); it != v[D].end (); it ++)
            if (cf[*it][D] > 0 && t[*it] != -1)
            {
                t[D] = *it;
                int mini = 1000000;
                for (int i=D; i!=S; i=t[i])
                    if (cf[t[i]][i] < mini) mini = cf[t[i]][i];
                flow += mini;
                for (int i=D; i!=S; i=t[i])
                    cf[t[i]][i] -= mini, cf[i][t[i]] += mini;
            }
    }
    return flow;
}

void Clear (int N)
{
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            cf[i][j] = 0;
    for (int i=1; i<=N; i++)
        v[i].clear ();
}

void add_to_tree (int x, int y, int z)
{
    h[x].push_back (make_pair (y, z));
    h[y].push_back (make_pair (x, z));
}

int BuildGomoryHu ()
{
    int sum = 0, nr = 1, g[216], id[216], id_g[216];
    vector < pair < pair < int, int >, int > > edges;
    for (int i=1; i<=N; i++)
        g[i] = 1;
    while (nr < N)
    {
        int X, Y, Z, n = 0;
        for (int i=1; i<=N; i++)
            for (int j=i + 1; j<=N; j++)
                if (g[i] == g[j])
                    X = i, Y = j;
        for (int i=1; i<=N; i++)
            if (g[i] == g[X]) id[i] = ++ n;
        for (int i=1; i<=nr; i++)
            if (i != g[X]) id_g[i] = ++ n;
        for (int i=1; i<=M; i++)
        {
            int a = x[i], b = y[i];
            if (g[a] == g[X]) a = id[a];
            else a = id_g[g[a]];
            if (g[b] == g[X]) b = id[b];
            else b = id_g[g[b]];
            add_edge (a, b, z[i]);
        }
        Z = max_flow (n, id[X], id[Y]), sum += Z;
        for (int i=1; i<=N; i++)
            if (g[i] == g[X] && t[id[i]] == -1) g[i] = nr + 1;
        for (vector < pair < pair < int, int >, int > > :: iterator it = edges.begin (); it != edges.end (); it ++)
        {
            if (it->first.first == g[X] && t[id_g[it->first.second]] == -1) it->first.first = nr + 1;
            if (it->first.second == g[X] && t[id_g[it->first.first]] == -1) it->first.second = nr + 1;
        }
        edges.push_back (make_pair (make_pair (g[X], nr + 1), Z));
        nr ++, Clear (n);
    }
    for (vector < pair < pair < int, int >, int > > :: iterator it = edges.begin (); it != edges.end (); it ++)
        add_to_tree (it->first.first, it->first.second, it->second);
    for (int i=1; i<=N; i++)
        name[g[i]] = i;
    return sum;
}

void PrintTree ()
{
    for (int i=1; i<=N; i++)
        for (vector < pair < int, int > > :: iterator it = h[i].begin (); it != h[i].end (); it ++)
            if (it->first > i) printf ("%d %d %d\n", name[i], name[it->first], it->second);
    /*for (int i=1; i<=N; i++)
        for (vector < pair < int, int > > :: iterator it = h[i].begin (); it != h[i].end (); it ++)
            if (it->first > i) printf ("%d %d %d\n", i, it->first, it->second);*/
}

vector < int > operator + (vector < int > a, vector < int > b)
{
    for (vector < int > :: iterator it = b.begin (); it != b.end (); it ++)
        a.push_back (*it);
    return a;
}

void dfs (int nod, int tata, vector < int > &comp)
{
    comp.push_back (nod);
    for (vector < pair < int, int > > :: iterator it = h[nod].begin (); it != h[nod].end (); it ++)
        if (it->first != tata && in_mul[it->first]) dfs (it->first, nod, comp);
}

void PrintVector (vector < int > v)
{
    for (vector < int > :: iterator it = v.begin (); it != v.end (); it ++)
    {
        printf ("%d", *it);
        if (it + 1 != v.end ()) printf (",");
    }
}

vector < int > solve (vector < int > mul)
{
    vector < int > ans;
    if (mul.size () == 1)
    {
        ans.push_back (mul[0]);
        return ans;
    }
    int mini = 1000000, X, Y;
    memset (in_mul, 0, sizeof (in_mul));
    for (vector < int > :: iterator it = mul.begin (); it != mul.end (); it ++)
        in_mul[*it] = 1;
    for (vector < int > :: iterator it = mul.begin (); it != mul.end (); it ++)
        for (vector < pair < int, int > > :: iterator it2 = h[*it].begin (); it2 != h[*it].end (); it2 ++)
            if (in_mul[it2->first] && it2->second < mini)
                mini = it2->second, X = *it, Y = it2->first;
    vector < int > mul1, mul2;
    dfs (X, Y, mul1);
    dfs (Y, X, mul2);
//    PrintVector (mul), printf (" = "), PrintVector (mul1), printf (" + "), PrintVector (mul2), printf ("\n");
    ans = solve (mul1) + solve (mul2);
    return ans;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=M; i++)
    scanf ("%d %d %d", &x[i], &y[i], &z[i]);
printf ("%d\n", BuildGomoryHu ());
//PrintTree ();
vector < int > param;
for (int i=1; i<=N; i++)
    param.push_back (i);
vector < int > ans = solve (param);
for (vector < int > :: iterator it = ans.begin (); it != ans.end (); it ++)
    printf ("%d ", name[*it]);
printf ("\n");
return 0;
}