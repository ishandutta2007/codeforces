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

int mod, nr, N, M, cod[109][109], ap[100009], Ap[100009], st[100009], in_q[100009], sum[100009];
bool ok;
vector < pair < int , int > > v[100009];

bitset < 109 > gs[1009];

void finish (int p)
{
    int sol = 1;
    for (int i=1; i<=p; i++)
    {
        sol += sol;
        if (sol >= mod)
            sol -= mod;
    }
    printf ("%d\n", sol);
}

void dfs (int nod, int val)
{
    ap[nod] = 1;
    st[++nr] = nod;
    sum[nr] = sum[nr - 1] ^ val;
    in_q[nod] = nr;
    for (vector < pair < int , int > > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
    {
        if (ap[it->first] == 0)
            dfs (it->first, it->second);
        else
        if (in_q[it->first])
        {
            if ((sum[in_q[it->first]] ^ sum[nr] ^ it->second) == ((nr - in_q[it->first]) % 2) && in_q[it->first] != nr - 1)
                ok = 0;
        }
    }
    in_q[nod] = 0;
    nr --;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);
mod = 1000000007;
scanf ("%d %d", &N, &M);
if (M == 0)
{
    finish (N - 1);
    return 0;
}
for (int i=1; i<=M; i++)
{
    int x, y, z;
    scanf ("%d %d %d", &x, &y, &z);
    v[x].push_back (make_pair (y, z));
    v[y].push_back (make_pair (x, z));
    Ap[x] = Ap[y] = 1;
}
int ans = 0;
ok = 1;
for (int i=1; i<=N; i++)
    if (ap[i] == 0)
    {
        nr = 0;
        ans ++;
        dfs (i, 0);
    }
if (ok)
{
    finish (ans - 1);
    return 0;
}
printf ("0\n");
/*scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    for (int j=i+1; j<=N; j++)
        cod[i][j] = cod[j][i] = ++nr, ap[nr] = -1;

for (int i=1; i<=M; i++)
{
    int x, y, val;
    scanf ("%d %d %d", &x, &y, &val);
    ap[cod[x][y]] = ap[cod[y][x]] = val;
    Ap[cod[x][y]] = 1;
}

for (int i=1; i<=N; i++)
    for (int j=i+1; j<=N; j++)
        for (int k=j+1; k<=N; k++)
        {
            if (ap[cod[i][j]] != -1 && ap[cod[j][k]] != -1 && ap[cod[i][k]] != -1)
            {
                if ((ap[cod[i][j]] + ap[cod[i][k]] + ap[cod[j][k]]) % 2 == 0)
                {
                    printf ("0\n");
                    return 0;
                }
                continue;
            }
            M ++;
            int s = 0;
            if (ap[cod[i][j]] != -1)
                s ^= ap[cod[i][j]];
            else
                gs[M][cod[i][j]] = 1;

            if (ap[cod[j][k]] != -1)
                s ^= ap[cod[j][k]];
            else
                gs[M][cod[j][k]] = 1;

            if (ap[cod[i][k]] != -1)
                s ^= ap[cod[i][k]];
            else
                gs[M][cod[i][k]] = 1;

            gs[M][nr + 1] = s ^ 1;
        }

//for (int i=1; i<=N; i++, printf ("\n"))
  //  for (int j=1; j<=N; j++)
    //    printf ("%d", cod[i][j]);

for (int i=1; i<=M; i++)
{
    int p = -1;
    for (int j=1; j<=nr + 1; j++)
        if (gs[i][j])
        {
            p = j;
            break;
        }
    if (p == -1)
        continue;
    Ap[p] = 1;
    if (p == nr + 1)
    {
        printf ("0\n");
        return 0;
    }
    for (int j=i+1; j<=M; j++)
        if (gs[j][p] == 1)
            gs[j] ^= gs[i];
}

for (int i=1; i<=M; i++)
{
    for (int j=1; j<=nr + 1; j++)
    {
        if (gs[i][j])
            printf ("1");
        else
            printf ("0");
        if (j == nr)
            printf (" ");
    }
    printf ("\n");
}

int sol = 1;
for (int i=1; i<=nr; i++)
    if (Ap[i] == 0)
        sol += sol;
printf ("%d\n", sol);*/

return 0;
}