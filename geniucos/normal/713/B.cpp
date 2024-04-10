#include<bits/stdc++.h>

using namespace std;

int N, a1, b1, a2, b2, c1, d1, c2, d2;

int A1, B1, A2, B2, C1, D1, C2, D2, Steps = 0;
bool do_deb = 0;

int qry (int a1, int b1, int a2, int b2)
{
    printf ("? %d %d %d %d\n", a1, b1, a2, b2), Steps ++;
    fflush (stdout);
    int ans;
    if (!do_deb)
    {
        scanf ("%d", &ans);
        fflush (stdout);
        return ans;
    }
    else
    {
        ans = 0;
        if (a1 <= A1 && A2 <= a2 && b1 <= B1 && B2 <= b2) ans ++;
        if (a1 <= C1 && C2 <= a2 && b1 <= D1 && D2 <= b2) ans ++;
        return ans;
    }
}

void get_bounding_box (int a1, int b1, int a2, int b2, int &X, int &Y, int &X2, int &Y2, int val)
{
    X = a1, Y = b1, X2 = a2, Y2 = b2;
    int p, u, mij;
    //if (bit1)
    //{
        p = a1, u = a2;
        while (p <= u)
        {
            mij = (p + u) >> 1;
            if (qry (a1, b1, mij, b2) == val) X2 = mij, u = mij - 1;
            else p = mij + 1;
        }
    //}
    //if (bit2)
   // {
        p = a1, u = a2;
        while (p <= u)
        {
            mij = (p + u) >> 1;
            if (qry (mij, b1, a2, b2) == val) X = mij, p = mij + 1;
            else u = mij - 1;
        }
    //}
    //if (bit3)
    //{
        p = b1, u = b2;
        while (p <= u)
        {
            mij = (p + u) >> 1;
            if (qry (a1, b1, a2, mij) == val) Y2 = mij, u = mij - 1;
            else p = mij + 1;
        }
    //}
    //if (bit4)
   // {
        p = b1, u = b2;
        while (p <= u)
        {
            mij = (p + u) >> 1;
            if (qry (a1, mij, a2, b2) == val) Y = mij, p = mij + 1;
            else u = mij - 1;
        }
    //}
}

void Deb ()
{
    scanf ("%d %d %d %d", &A1, &B1, &A2, &B2);
    scanf ("%d %d %d %d", &C1, &D1, &C2, &D2), do_deb = 1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
//Deb ();
fflush (stdout);
int p = 1, u = N, mij, ras;
while (p <= u)
{
    mij = (p + u) >> 1;
    if (qry (1, 1, mij, N) >= 1) ras = mij, u = mij - 1;
    else p = mij + 1;
}
if (ras < N && qry (ras + 1, 1, N, N) == 1)
{
    get_bounding_box (1, 1, ras, N, a1, b1, a2, b2, 1);
    get_bounding_box (ras + 1, 1, N, N, c1, d1, c2, d2, 1);
}
else
{
    p = 1, u = N;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (qry (1, 1, N, mij) >= 1) ras = mij, u = mij - 1;
        else p = mij + 1;
    }
    get_bounding_box (1, 1, N, ras, a1, b1, a2, b2, 1);
    get_bounding_box (1, ras + 1, N, N, c1, d1, c2, d2, 1);
}
printf ("! %d %d %d %d %d %d %d %d\n", a1, b1, a2, b2, c1, d1, c2, d2);
if (do_deb) printf ("! %d %d %d %d %d %d %d %d     %d\n", A1, B1, A2, B2, C1, D1, C2, D2, Steps);
return 0;
}