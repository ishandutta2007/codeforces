#include<cstdio>
#include<bitset>
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

int N, M, l[300009];
double C[1200009], S[1200009], add[1200009], PI = acos (-1.0), eps = 1e-6;

void Build (int nod, int st, int dr)
{
    C[nod] = (double) dr - st + 1;
    if (st == dr) return ;
    int mij = (st + dr) >> 1;
    Build (nod << 1, st, mij);
    Build ((nod << 1) + 1, mij + 1, dr);
}

void addU (int nod, double U, double cs, double sn)
{
    double oldS = S[nod], oldC = C[nod];
    S[nod] = (double) oldS * cs + oldC * sn;
    C[nod] = (double) oldC * cs - oldS * sn;
    add[nod] += U;
}

void split (int nod)
{
    if (add[nod] > eps || add[nod] < eps)
    {
        double cs = cos (add[nod]), sn = sin (add[nod]);
        addU (nod << 1, add[nod], cs, sn);
        addU ((nod << 1) + 1, add[nod], cs, sn);
        add[nod] = 0;
    }
}

void Update1 (int nod, int st, int dr, int pos, int val)
{
    if (st == dr)
    {
        double rap = (double) (l[pos] + val) / (double) l[pos];
        S[nod] = (double) S[nod] * rap;
        C[nod] = (double) C[nod] * rap;
        l[pos] += val;
        return ;
    }
    int mij = (st + dr) >> 1;
    split (nod);
    if (pos <= mij) Update1 (nod << 1, st, mij, pos, val);
    else Update1 ((nod << 1) + 1, mij + 1, dr, pos, val);
    S[nod] = S[nod << 1] + S[(nod << 1) + 1];
    C[nod] = C[nod << 1] + C[(nod << 1) + 1];
}

void Update2 (int nod, int st, int dr, int x, int y, double U, double cs, double sn)
{
    if (x <= st && dr <= y)
    {
        addU (nod, U, cs, sn);
        return ;
    }
    int mij = (st + dr) >> 1;
    split (nod);
    if (x <= mij) Update2 (nod << 1, st, mij, x, y, U, cs, sn);
    if (y > mij) Update2 ((nod << 1) + 1, mij + 1, dr, x, y, U, cs, sn);
    S[nod] = S[nod << 1] + S[(nod << 1) + 1];
    C[nod] = C[nod << 1] + C[(nod << 1) + 1];
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    l[i] = 1;
///for (int i=1; i<=N; i++)
   /// beta[i] = 0.0, l[i] = 1.0;
Build (1, 1, N);
while (M --)
{
    int tip, x, y;
    scanf ("%d %d %d", &tip, &x, &y);
    if (tip == 1) Update1 (1, 1, N, x, y);///, l[x] += y;
    else
    {
        double unghi = - (double) y * PI / 180.0, cs = cos (unghi), sn = sin (unghi);
        Update2 (1, 1, N, x, N, unghi, cs, sn);
        ///for (int i=x; i<=N; i++)
           /// beta[i] += unghi;
    }
/*    double a = 0, b = 0;
    for (int i=1; i<=N; i++)
        a = (double) a + l[i] * cos (beta[i]), b = (double) b + l[i] * sin (beta[i]);*/
    printf ("%.10lf %.10lf\n", C[1], S[1]);
}

return 0;
}