#include<bits/stdc++.h>

using namespace std;

int ans, N, stupidP[200009], h[200009], P[200009], vol[200009], Pi[200009], revProd[200009], primeDivisors[200009][7];
vector < int > v[200009];
const int mod = 1e9 + 7;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}
int power (int a, int b) {int ans = 1; while (b) {if (b & 1)
ans = mul (ans, a); a = mul (a, a), b >>= 1;} return ans;}

void init ()
{
    for (int i=1; i<=N; i++)
        Pi[i] = i;
    for (int i=2; i<=N; i++)
        if (Pi[i] == i)
        {
            for (int j=i; j<=N; j+=i)
                Pi[j] /= i, Pi[j] *= i - 1, primeDivisors[j][++primeDivisors[j][0]] = i;
            revProd[i] = mul (i, power (i - 1, mod - 2));
        }
}

int sumPi[20][200009], sumProdPi[20][200009];
bool exists[20][200009];
int whatIsInside[20][200009], q[20][200009];
void addVal (int lev, int x)
{
    for (int msk = 0; msk < (1 << primeDivisors[x][0]); msk ++)
    {
        int curr = 1;
        for (int i=0; i<primeDivisors[x][0]; i++)
            if (msk & (1 << i))
                curr *= primeDivisors[x][i + 1];
        if (exists[lev][curr] == 0)
            exists[lev][curr] = 1, whatIsInside[lev][++whatIsInside[lev][0]] = curr;
        adto (sumPi[lev][curr], Pi[x]);
        adto (sumProdPi[lev][curr], mul (Pi[x], h[x]));
    }
    q[lev][++q[lev][0]] = x;
}

void spill (int frm, int to)
{
    for (int currId = 1; currId<=whatIsInside[frm][0]; currId ++)
    {
        int i = whatIsInside[frm][currId];
        exists[frm][i] = 0;
        adto (sumPi[to][i], sumPi[frm][i]);
        adto (sumProdPi[to][i], sumProdPi[frm][i]);
        sumPi[frm][i] = sumProdPi[frm][i] = 0;
        if (exists[to][i] == 0)
            exists[to][i] = 1, whatIsInside[to][++whatIsInside[to][0]] = i;
    }
    for (int i=1; i<=q[frm][0]; i++)
        q[to][++q[to][0]] = q[frm][i];
    whatIsInside[frm][0] = 0, q[frm][0] = 0;
}

void dfsInit (int nod, int tata)
{
    vol[nod] = 1, P[nod] = -1;
    for (auto it : v[nod])
        if (it != tata)
        {
            h[it] = h[nod] + 1, dfsInit (it, nod);
            if (P[nod] == -1 || vol[it] > vol[P[nod]])
                P[nod] = it;
            vol[nod] += vol[it];
        }
}

int sumPiMsk[70], sumProdPiMsk[70];
void addCombo (int lev, int lca, int x)
{
    for (int msk = 0; msk < (1 << primeDivisors[x][0]); msk ++)
        sumPiMsk[msk] = sumProdPiMsk[msk] = 0;
    for (int msk = (1 << primeDivisors[x][0]) - 1; msk >= 0; msk --)
    {
        int curr = 1, revCurr = 1;
        for (int i=0; i<primeDivisors[x][0]; i++)
            if (msk & (1 << i))
                curr *= primeDivisors[x][i + 1], revCurr = mul (revCurr, revProd[primeDivisors[x][i + 1]]);

        adto (sumPiMsk[msk], sumPi[lev][curr]), adto (sumProdPiMsk[msk], sumProdPi[lev][curr]);
        if (msk > 0)
        {
            for (int subMsk = (msk - 1) & msk; ; subMsk = (subMsk - 1) & msk)
            {
                sumPiMsk[subMsk] = subtract (sumPiMsk[subMsk], sumPiMsk[msk]),
                sumProdPiMsk[subMsk] = subtract (sumProdPiMsk[subMsk], sumProdPiMsk[msk]);
                if (subMsk == 0) break;
            }
        }

        int valueToUpdateWith = add (sumProdPiMsk[msk], mul (sumPiMsk[msk], (h[x] - 2 * h[lca] + mod) % mod));
        valueToUpdateWith = mul (valueToUpdateWith, mul (Pi[x], revCurr));
        adto (ans, valueToUpdateWith);
    }
}

void solve (int nod, int tata, int lev)
{
    if (P[nod] == -1)
    {
        addVal (lev, nod);
        return ;
    }
    solve (P[nod], nod, lev);
    addCombo (lev, nod, nod);
    addVal (lev, nod);
    for (auto it : v[nod])
        if (it != tata && it != P[nod])
        {
            solve (it, nod, lev + 1);
            for (int currId = 1; currId <= q[lev + 1][0]; currId ++)
                addCombo (lev, nod, q[lev + 1][currId]);
            spill (lev + 1, lev);
        }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), init ();
for (int i=1; i<=N; i++)
    scanf ("%d", &stupidP[i]);
for (int i=1; i<N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    x = stupidP[x], y = stupidP[y];
    v[x].push_back (y);
    v[y].push_back (x);
}
dfsInit (1, -1);
solve (1, -1, 0);
ans = mul (ans, power (mul (N, N - 1), mod - 2));
printf ("%d\n", add (ans, ans));

return 0;
}