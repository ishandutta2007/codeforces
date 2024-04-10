#include<bits/stdc++.h>

using namespace std;

int N, L, R, how[50], x[10009], y[10009];
bool isBase[10009];
vector < pair < int, int > > lft, rgt, mid, ans;

void doSwap (int lin, int i, int j, vector < pair < int, int > > &v)
{
    if (i == j) return ;
    if (lin == 0) swap (x[i], x[j]);
    else swap (y[i], y[j]);
    v.push_back ({i, j}), v.push_back ({j, i}), v.push_back ({i, j});
}

int turnToBase (int lin, int x[], vector < pair < int, int > > &ans)
{
    for (int i=1; i<=N; i++)
    {
        int k = -1;
        for (int j=0; j<30; j++)
            if (x[i] & (1 << j))
            {
                k = j;
                break;
            }
        if (k == -1)
        {
            isBase[i] = 0;
            continue;
        }
        isBase[i] = 1;
        for (int j=i + 1; j<=N; j++)
            if (x[j] & (1 << k))
                x[j] ^= x[i], ans.push_back ({j, i});
    }
    int j = 0;
    for (int i=1; i<=N; i++)
        if (isBase[i])
            doSwap (lin, ++j, i, ans);
    return j;
}

int writeVal (int val)
{
    int aux[50];
    for (int i=1; i<=L; i++)
        aux[i] = x[i];
    x[0] = val;
    for (int i=0; i<=L; i++)
        how[i] = 1 << i;
    for (int i=L; i>=0; i--)
    {
        int k = -1;
        for (int j=0; j<30; j++)
            if (x[i] & (1 << j))
            {
                k = j;
                break;
            }
        if (k == -1) continue;
        for (int j=i - 1; j>=0; j--)
            if (x[j] & (1 << k))
                x[j] ^= x[i], how[j] ^= how[i];
    }
    for (int i=1; i<=L; i++)
        x[i] = aux[i];
    if (x[0] != 0)
    {
        printf ("-1\n");
        exit (0);
    }
    return how[0];
}

void doMidStuff ()
{
    for (int i=1; i<=R; i++)
    {
        int msk = writeVal (y[i]);
        for (int j=i; j<=L; j++)
            if (msk & (1 << j))
            {
                if (j != i)
                {
                    swap (x[i], x[j]);
                    mid.push_back ({i, j});
                    mid.push_back ({j, i});
                    mid.push_back ({i, j});
                }
                msk ^= 1 << j;
                break;
            }
        for (int j=1; j<=L; j++)
            if (msk & (1 << j))
                x[i] ^= x[j], mid.push_back ({i, j});
    }
    for (int i=R + 1; i<=L; i++)
        mid.push_back ({i, i});
}

void check ()
{
    ifstream f ("input");
    f >> N;
    for (int i=1; i<=N; i++)
        f >> x[i];
    for (int i=1; i<=N; i++)
        f >> y[i];
    f.close ();
    ifstream f2 ("output");
    int L;
    f2 >> L;
    while (L --)
    {
        int i, j;
        f2 >> i >> j;
        x[i] ^= x[j];
    }
    f2.close ();
    for (int i=1; i<=N; i++)
        printf ("%d%c", x[i], " \n"[i == N]);
    for (int i=1; i<=N; i++)
        printf ("%d%c", y[i], " \n"[i == N]);
    exit (0);
}

void print (vector < pair < int, int > > ans)
{
    printf ("%d\n", ans.size ());
    for (auto it : ans)
        printf ("%d %d\n", it.first, it.second);
}

int main ()
{
//check ();
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &x[i]);
for (int i=1; i<=N; i++)
    scanf ("%d", &y[i]);
L = turnToBase (0, x, lft);
//print (lft);
//return 0;
R = turnToBase (1, y, rgt);
//print (rgt);
//return 0;
doMidStuff ();
for (auto it : lft)
    ans.push_back (it);
for (auto it : mid)
    ans.push_back (it);
//print (ans);
//return 0;
reverse (rgt.begin (), rgt.end ());
for (auto it : rgt)
    ans.push_back (it);
print (ans);
return 0;
}