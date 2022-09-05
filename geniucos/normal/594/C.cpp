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

int N, K, x[100009], y[100009], ap[100009];
long long mini;
priority_queue < pair < int , int > > PQ[4];

int Get_Top (int lin)
{
    pair < int , int > curr;
    while (!PQ[lin].empty ())
    {
        curr = PQ[lin].top ();
        if (ap[curr.second] == 0) return curr.second;
        PQ[lin].pop ();
    }
}

void add (int i)
{
    PQ[0].push (make_pair (x[i], i));///sus
    PQ[1].push (make_pair (-x[i], i));///jos
    PQ[2].push (make_pair (y[i], i));///dreapta
    PQ[3].push (make_pair (-y[i], i));///stanga
}

int mod (int x)
{
    if (x < 0) return -x;
    return x;
}

int get_l (int L)
{
    if (L & 1) return (L + 1) >> 1;
    if (L == 0) return 1;
    return (L >> 1);
}

void back (int pos)
{
    if (pos == K + 1)
    {
        long long curr, i, j, k, l;
        i = Get_Top (0), j = Get_Top (1);
        k = Get_Top (2), l = Get_Top (3);
        curr = 1LL * get_l (mod (x[i] - x[j])) * get_l (mod (y[k] - y[l]));
        if (curr < mini) mini = curr;
        return ;
    }
    for (int i=0; i<4; i++)
    {
        int curr_i = Get_Top (i);
        ap[curr_i] = 1, back (pos + 1), ap[curr_i] = 0;
        add (curr_i);
    }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
if (K == N - 1)
{
    printf ("1\n");
    return 0;
}
for (int i=1; i<=N; i++)
{
    int a1, b1, a2, b2;
    scanf ("%d %d %d %d", &a1, &b1, &a2, &b2);
    x[i] = a1 + a2, y[i] = b1 + b2;
    add (i);
}
mini = 1LL << 62;
back (1);
printf ("%I64d\n", mini);

return 0;
}