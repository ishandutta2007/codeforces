#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>

using namespace std;

int N, a[100009], A, B;
map < int , int > mp;

class SAT
{
    public:

    int n_Q, N, sol[200009], ap[200009], Q[200009];
    vector < int > v[200009], h[200009];

    int cod (int v)
    {
        if (v < 0) return N - v;
        return v;
    }

    int opus (int x)
    {
        if (x<=N) return N + x;
        return x - N;
    }

    void Add_Implication (int x, int y, int tip)
    {
        if (tip == 0)
            Add_Implication (-y, -x, tip ^ 1);
        //printf ("%d -> %d\n", x, y);
        v [ cod ( x ) ] . push_back ( cod ( y ) );////graf normal
        h [ cod ( y ) ] . push_back ( cod ( x ) );////graf transpus
    }

    void Add_Clauza (int x, int y)
    {
        Add_Implication (-x, y, 0);
        Add_Implication (-y, x, 0);
    }

    void dfs (int nod)
    {
        ap[nod] = 1;
        for (vector < int > :: iterator it = v[nod].begin(); it != v[nod].end(); it++)
            if (ap[*it] == 0)
                dfs (*it);
        Q[++n_Q] = nod;
    }

    void dfp (int nod)
    {
        if (sol[nod])
        {
            sol[0] = -1;
            return ;
        }

        ap[nod] = sol[nod] = 0;
        sol[opus(nod)] = 1;
        for (vector < int > :: iterator it = h[nod].begin(); it != h[nod].end(); it++)
            if (ap[*it] == 1)
                dfp (*it);
    }

    int solve ()
    {
        for (int i=1; i<=2*N; i++)
            if (ap[i] == 0)
                dfs (i);

        for (int i=n_Q; i>=1; i--)
            if (ap[Q[i]] && ap[opus(Q[i])])
                dfp (Q[i]);

        return sol[0];
    }
}sistem;

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &A, &B), sistem.N = N;
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), mp[a[i]] = i;

for (int i=1; i<=N; i++)
{
    int v1, v2;
    v1 = mp[A - a[i]];
    v2 = mp[B - a[i]];
    if (v1 != 0) sistem.Add_Implication (-i, -v1, 0);
    else sistem.Add_Implication (-i, i, 0);
    if (v2 != 0) sistem.Add_Implication (i, v2, 0);
    else sistem.Add_Implication (i, -i, 0);
}

if (sistem.solve () == -1)
{
    printf ("NO\n");
    return 0;
}

printf ("YES\n");
for (int i=1; i<=N; i++)
    printf ("%d ", sistem.sol[i]);
printf ("\n");

return 0;
}