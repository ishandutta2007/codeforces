#include<bits/stdc++.h>

using namespace std;

int N, a[109];
long long answer, K;
vector < int > ds;

void addSegm (long long st, long long dr)
{
    long long sus = K, jos = N;
    for (int i=1; i<=N; i++)
        sus += a[i], jos += (a[i] - 1) / st;
    long long Lim2 = sus / jos;
    if (Lim2 >= st)
    {
        if (dr < Lim2)
            Lim2 = dr;
        if (Lim2 > answer)
            answer = Lim2;
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %I64d", &N, &K);
for (int i=1; i<=N; i++)
{
    scanf ("%d", &a[i]);
    int X = a[i] - 1;
    for (int j=1; j<=X; j++)
    {
        int b = X / j, k = X / b;
        ds.push_back (j);
        j = k;
    }
    ds.push_back (a[i] + 1);
}
sort (ds.begin (), ds.end ());
ds.erase (unique (ds.begin (), ds.end ()), ds.end ());
for (int ii=0; ii<ds.size (); ii++)
{
    long long st = ds[ii], dr;
    if (ii + 1 < ds.size ()) dr = ds[ii + 1] - 1;
    else dr = 1LL << 50;
    addSegm (st, dr);
}
printf ("%I64d\n", answer);
return 0;
}