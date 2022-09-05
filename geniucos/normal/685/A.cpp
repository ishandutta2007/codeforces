#include<bits/stdc++.h>

using namespace std;

int sol, X, Y, ap[50], val[50], put[50], N, M;

int lgt (int val)
{
    if (val == 0) return 1;
    int nr = 0;
    while (val) nr ++, val /= 7;
    return nr;
}

void back (int pos)
{
    if (pos == X + Y + 1)
    {
        int v1 = 0, v2 = 0;
        //if (val[2] == 6)
          //  val[2] = 6;
        for (int i=1; i<=X; i++)
            v1 += val[i] * put[i - 1];
        for (int i=X + 1; i<=X + Y; i++)
            v2 += val[i] * put[i - X - 1];
        sol += (v1 <= N && v2 <= M);
/*        if (v1 <= N && v2 <= M)
        {
            for (int i=1; i<=X + Y; i++)
                printf ("%d", val[i]);
            printf (" %d %d\n", v1, v2);
        }*/
        return ;
    }
    for (int i=0; i<7; i++)
        if (ap[i] == 0)
            ap[i] = 1, val[pos] = i, back (pos + 1), ap[i] = 0;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M), N --, M --;
X = lgt (N), Y = lgt (M), put[0] = 1;
//printf ("%d %d\n", X, Y);
if (X + Y > 7)
{
    printf ("0\n");
    return 0;
}
for (int i=1; i<=10; i++)
    put[i] = put[i - 1] * 7;
back (1);
printf ("%d\n", sol);
return 0;
}