#include<bits/stdc++.h>

using namespace std;

int ans, N, lev[100009], lg[100009], t[18][100009];
long long rmq[18][100009], a[100009];
vector < int > v[100009];
const int mod = 1e9 + 7;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

long long gcd (long long a, long long b)
{
    long long r;
    while (b)
        r = a % b,
        a = b,
        b = r;
    return a;
}

void solve (int nod)
{
    int q = nod, lastLevelConsidered = lev[nod] + 1;
    long long curr = a[nod];
    while (1)
    {
        ///first I push it as high as possible
        ///i know nod..q inclusive -> curr
        if (q != 1)
        {
            q = t[0][q];///curr has considered all till q except q
            for (int i=lg[lev[q]]; i>=0; i--)
                if (lev[q] - (1 << i) >= 0 && gcd (curr, rmq[i][q]) == curr)
                    q = t[i][q];
            ///q is just above what I need
        }
        else q = 0;
        ///for nodes on all levels between lev[q] + 1, .., lastLevelConsidered - 1 it's curr
        adto (ans, mul (curr % mod, lastLevelConsidered - lev[q] - 1));
        curr = gcd (curr, a[q]), lastLevelConsidered = lev[q] + 1;
        if (q == 0) break;
    }
}

void dfs (int nod)
{
    for (int i=1; (1 << i) <= lev[nod]; i++)
        t[i][nod] = t[i - 1][t[i - 1][nod]],
        rmq[i][nod] = gcd (rmq[i - 1][nod], rmq[i - 1][t[i - 1][nod]]);
    solve (nod);
    for (auto it : v[nod])
        if (t[0][nod] != it)
            t[0][it] = nod, lev[it] = lev[nod] + 1,
            dfs (it);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);


scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%I64d", &a[i]), rmq[0][i] = a[i];
lg[1] = 0;
for (int i=2; i<=N; i++)
{
    lg[i] = lg[i - 1];
    if ((2 << lg[i]) <= i)
        lg[i] ++;
}
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}
t[0][1] = 0, lev[1] = 1, dfs (1);
printf ("%d\n", ans);
return 0;
}