#include<bits/stdc++.h>

using namespace std;

int ans = 1, sz, any0, any1, anyL, N, ap[200009], col[200009];
const int mod = 1e9 + 7;
vector < int > v[200009];

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

void dfs (int nod)
{
    col[nod] = 1, sz ++, anyL |= (ap[nod] == nod);
    any0 |= (ap[nod] == 0);
    any1 |= (ap[nod] != 0);
    for (auto it : v[nod])
        if (col[it] == 0)
            dfs (it);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    ap[x] = y;
    v[x].push_back (y);
    v[y].push_back (x);
}
for (int i=1; i<=2 * N; i++)
    if (col[i] == 0)
    {
        sz = 0, any0 = 0, any1 = 0, anyL = 0, dfs (i);
        if (any1 == 0) continue;
        if (any0) ans = mul (ans, sz);
        else
        {
            if (anyL) ;
            else ans = mul (ans, 2);
        }
    }
printf ("%d\n", ans);

return 0;
}