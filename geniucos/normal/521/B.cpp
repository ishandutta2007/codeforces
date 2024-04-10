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

int mod, ans, N, deja[100009], pot[100009], x[100009], y[100009], sol[100009];
map < pair < int , int > , int > pos;
priority_queue < int > hp1, hp2;

int P (int i, int j)
{
    return pos[make_pair (i, j)];
}

bool ok (int x, int y)
{
    if (P(x - 1, y + 1) != 0)
    {
        if (P (x - 2, y) || P (x - 1, y))
            ;
        else
            return 0;
    }
    if (P (x, y + 1))
    {
        if (P(x-1, y) || P(x+1, y))
            ;
        else
            return 0;
    }
    if (P(x+1, y+1))
    {
        if (P (x+1, y) || P (x+2, y))
            ;
        else
            return 0;
    }
    return 1;
}

void refresh (int x, int y)
{
    if (P(x, y) == 0)
        return ;
    int v = P(x, y);
    bool msj = ok(x, y);
    if (msj == 0)
    {
        if (pot[v] == 1)
            pot[v] = 0;
    }
    else
    {
        if (pot[v] == 0 && deja[v] == 0)
        {
            pot[v] = 1;
            hp1.push (v);
            hp2.push (-v);
        }
    }
}

void take (int v)
{
    pos[make_pair(x[v], y[v])] = 0;
    refresh (x[v]-1, y[v]);
    refresh (x[v]+1, y[v]);
    refresh (x[v]-2, y[v]);
    refresh (x[v]+2, y[v]);
    refresh (x[v]-1, y[v] - 1);
    refresh (x[v], y[v] - 1);
    refresh (x[v]+1, y[v] - 1);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    scanf ("%d %d", &x[i], &y[i]);
    pos[make_pair (x[i], y[i])] = i;
}

for (int i=1; i<=N; i++)
    refresh (x[i], y[i]);

for (int i=1; i<=N; i++)
{
    if (i & 1)
    {
        int curr;
        while (!hp1.empty())
        {
            curr = hp1.top();
            hp1.pop();
            if (pot[curr] == 0)
                continue;
            if (deja[curr])
                continue;
            deja[curr] = 1;
            sol[i] = curr;
            take (curr);
            break;
        }
    }
    else
    {
        int curr;
        while (!hp2.empty())
        {
            curr = -hp2.top();
            hp2.pop();
            if (pot[curr] == 0)
                continue;
            if (deja[curr])
                continue;
            deja[curr] = 1;
            sol[i] = curr;
            take (curr);
            break;
        }
    }
    /*printf ("%d %d\n", hp1.size(), hp2.size());
    if (i == 3)
        return 0;*/
}

/*for (int i=1; i<=N; i++)
    printf ("%d\n",sol[i]);
printf ("\n\n");*/

mod = 1000000009;
int baza = 1;
for (int i=N; i>=1; i--)
{
    sol[i] --;
    ans = ((long long)ans + 1LL * baza * sol[i]) % mod;
    baza = (1LL * baza * N) % mod;
}
printf ("%d\n", ans);

return 0;
}