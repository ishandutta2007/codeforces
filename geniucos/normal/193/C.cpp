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

int nr, how[20], ap[1009], a[109], b[10], fixed[10], gs[10], aux[10];
char sir[5][200009];
double G[10][10], eps = 1e-6;;

double mod (double x)
{
    if (x < 0) return -x;
    return x;
}

int nearest_integer (double v)
{
    int curr = (int) v, ans = -1;
    for (int i = curr - 1; i <= curr + 1; i++)
        if (mod ((double)i - v) < eps)
            ans = i;
    return ans;
}

void Print ()
{
    for (int i=1; i<=7; i++, printf ("\n"))
        for (int j=2; j<=8; j++)
        {
            printf ("%.3f ", G[i][j]);
            if (j == 7) printf ("  =  ");
        }
    printf ("\n\n");
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

for (int i=0; i<16; i++)
if (i & 1)
{
    for (int j=0; j<4; j++)
        a[j + 1] = ((i & (1<<j)) > 0);
    int pos = 0, msk = 0;
    for (int j=1; j<=4; j++)
        for (int k=j + 1; k<=4; k++)
        {
            if (a[j] != a[k])
                msk |= 1<<pos;
            pos ++;
        }
    ap[msk] = i + 1;
}

int nr = 0;
for (int i=1; i<=1000; i++)
    if (ap[i])
    {
        int cum = ap[i] - 1;
        how[++nr] = cum;
/*        for (int j=0; j<6; j++)
        {
            if (i & (1<<j)) printf ("1");
            else printf ("0");
        }
        printf (" -> ");
        for (int j=0; j<4; j++)
        {
            if (cum & (1<<j)) printf ("1");
            else printf ("0");
        }
        printf ("\n");*/
    }

/*
a1 + a2 + a5 + a6 = b1
a1 + a3 + a4 + a7 = b2
a1 + a3 + a5 + a7 = b3
a2 + a3 + a4 + a5 = b4
a2 + a3 + a6 + a7 = b5
a4 + a5 + a6 + a7 = b6
*/
int Mini = 10000000;
for (int i=1; i<=6; i++)
    scanf ("%d", &b[i]);
int lim = min (b[1], min (b[4], b[5]));
for (int a2 = 0; a2 <= lim; a2 ++)
{
    /*
    a1 = 0
    a2 = 0
    a3 = 2
    a4 = 0
    a5 = 2
    a6 = 2
    a7 = 0
    a1 + a2 + a5 + a6 = c1
    a1 + a3 + a4 + a6 = c2
    a1 + a3 + a5 + a7 = c3
    a2 + a3 + a4 + a5 = c4
    a2 + a3 + a6 + a7 = c5
    a4 + a5 + a6 + a7 = c6
    */
//    if (a2 == 1) break;
    G[1][1] = G[1][2] = G[1][5] = G[1][6] = 1.0, G[1][8] = (double) b[1];
    G[2][1] = G[2][3] = G[2][4] = G[2][6] = 1.0, G[2][8] = (double) b[2];
    G[3][1] = G[3][3] = G[3][5] = G[3][7] = 1.0, G[3][8] = (double) b[3];
    G[4][2] = G[4][3] = G[4][4] = G[4][5] = 1.0, G[4][8] = (double) b[4];
    G[5][2] = G[5][3] = G[5][6] = G[5][7] = 1.0, G[5][8] = (double) b[5];
    G[6][4] = G[6][5] = G[6][6] = G[6][7] = 1.0, G[6][8] = (double) b[6];
    G[7][2] = 1.0, G[7][8] = (double) a2;
    bool ok = 1;
    for (int i=1; i<=7; i++)
    {
        //Print ();
        int j;
        for (j=1; j<=8; j++)
            if (G[i][j] < -eps || G[i][j] > eps) break;
        if (j == 8)
        {
            ok = 0;
            break;
        }
        /*if (j > 8)
        {
            printf ("aku-i kktu\n");
            ok = 0;
            continue;
        }*/
        fixed[i] = j;
        for (int p=1; p<=7; p++)
            if ((G[p][j] < -eps || G[p][j] > eps) && p != i)
            {
                double R = (double) G[p][j] / G[i][j];
                for (int k=1; k<=8; k++)
                    G[p][k] = (double) G[p][k] - (double) G[i][k] * R;
            }
    }
    if (ok)
    {
        for (int i=1; i<=7; i++)
            gs[fixed[i]] = nearest_integer ((double) G[i][8] / G[i][fixed[i]]);
        for (int i=1; i<=7; i++)
            if (gs[i] < 0) ok = 0;
    }
    if (ok)
    {
        int ans = 0;
        for (int i=1; i<=7; i++)
            ans += gs[i];
        if (ans < Mini)
        {
            Mini = ans;
            for (int i=1; i<=7; i++)
                aux[i] = gs[i];
        }
    }
    for (int i=1; i<=7; i++)
        for (int j=2; j<=8; j++)
            G[i][j] = 0.0;
}
if (Mini == 10000000)
{
    printf ("-1\n");
    return 0;
}
printf ("%d\n", Mini);
for (int i=1; i<=Mini; i++)
{
    int curr = 0, j;
    for (j=1; j<=7; j++)
    {
        curr += aux[j];
        if (curr >= i) break;
    }
    for (int k=1; k<=4; k++)
        sir[k][i] = 'a' + ((how[j] & (1<<(k-1))) > 0);
}
for (int i=1; i<=4; i++)
    printf ("%s\n", sir[i] + 1);
return 0;
}