#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>
#include<map>

using namespace std;

int nr_prime_utile, nr, N, M, A[109], x[109], y[109], prim_util[1000009], cr[32000], pr[32000];

map < int , int > cod_prim;

class graph
{
    public:
    int flux, N, S, D, t[5009];
    int f[5009][5009], c[5009][5009];
    vector < int > muchii[5009];

    void Add_edge (int i, int j, int cost)
    {
        muchii[i].push_back(j);
        muchii[j].push_back(i);
        c[i][j] = cost;
    }

    bool bfs()
    {
        queue < int > q;
        for (int i=1; i<=N; i++)
            t[i] = -1;
        q.push(S);
        t[S] = 0;
        while (!q.empty())
        {
            int nod = q.front();
            q.pop();
            for (vector < int > :: iterator it = muchii[nod].begin(); it != muchii[nod].end(); it++)
                if (t[*it] == -1 && f[nod][*it] < c[nod][*it])
                {
                    t[*it] = nod;
                    if (*it == D) return 1;
                    q.push(*it);
                }
        }
        return 0;
    }

    int calc_flux()
    {
        flux = 0;
        while ( bfs() )
        {
            for (vector < int > :: iterator it = muchii[D].begin(); it != muchii[D].end(); it++)
                if (t[*it] != -1 && f[*it][D] < c[*it][D])
                {
                    int nod = *it, fmin = 100000;
                    t[D] = nod;
                    for (int i = D; i != S; i = t[i])
                        if (c[t[i]][i] - f[t[i]][i] < fmin)
                            fmin = c[t[i]][i] - f[t[i]][i];
                    flux += fmin;
                    for (int i = D; i != S; i = t[i])
                    {
                        f[t[i]][i] += fmin;
                        f[i][t[i]] -= fmin;
                    }
                }
        }
        return flux;
    }

    void Clear()
    {
        for (int i=1; i<=N; i++)
            for (vector < int > :: iterator it = muchii[i].begin(); it != muchii[i].end(); it++)
                f[i][*it] = 0;
    }
}graf;

void poate_add_prim (int prim)
{
    if (cod_prim[prim] == 0)
    {
        cod_prim[prim] = ++nr_prime_utile;
        prim_util[nr_prime_utile] = prim;
    }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

for (int i=2; i*i <= 31627; i++)
    if (cr[i] == 0)
    {
        for (int j=i*i; j<=31627; j+=i)
            cr[j] = 1;
    }

for (int i=2; i<=31627; i++)
    if (cr[i] == 0)
        pr[++nr] = i;

scanf ("%d", &N);
scanf ("%d", &M);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &A[i]);
    int aux = A[i];
    for (int j=1; j<=nr && pr[j] * pr[j] <= aux; j++)
        if (aux%pr[j] == 0)
        {
            poate_add_prim (pr[j]);
            while (aux%pr[j] == 0)
                aux /= pr[j];
        }
    if (aux != 1)
        poate_add_prim (aux);
}

for (int i=1; i<=M; i++)
{
    scanf ("%d %d", &x[i], &y[i]);
    if (x[i]%2 == 0)
    {
        int aux = x[i];
        x[i] = y[i];
        y[i] = aux;
    }
}

int sol = 0;

for (int II = 1; II <= nr_prime_utile; II++)
{
    int prim = prim_util[II];
    graf.S = 1;
    graf.D = 2;
    graf.N = N + 2;
    for (int i=1; i<=N; i+=2)
    {
        int E = 0, aux = A[i];
        while (aux % prim == 0)
            aux /= prim, E ++;
        graf.Add_edge (graf.S, i + 2, E);
    }
    for (int i=2; i<=N; i+=2)
    {
        int E = 0, aux = A[i];
        while (aux % prim == 0)
            aux /= prim, E ++;
        graf.Add_edge (i + 2, graf.D, E);
    }
    for (int i=1; i<=M; i++)
        graf.Add_edge (x[i] + 2, y[i] + 2, 100000);
    sol += graf.calc_flux();
    graf.Clear();
}
printf ("%d\n", sol);
return 0;
}