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

int N, M, M_dis, used[100009], B[100009], B_dis[100009], A[100009], how[100009], C[100009], prec[100009], dp[100009], gaps[100009];

void Read ()
{
    scanf ("%d", &N), A[1] = 0;
    for (int i=2; i<=N; i++)
        scanf ("%d", &A[i]);
    scanf ("%d", &A[N + 1]);
    A[N + 2] = 1000000003, A[N + 3] = 1000000003, N += 2;
    for (int i=1; i<=N; i++)
    {
        gaps[i] = gaps[i-1];
        if (A[i] == -1) gaps[i] ++;
    }

    scanf ("%d", &M);
    for (int i=1; i<=M; i++)
        scanf ("%d", &B[i]);
    sort (B + 1, B + M + 1);
    for (int i=1; i<=M; i++)
        if (B[i] != B[i-1] || i == 1)
            B_dis[++M_dis] = B[i];
}

int last_smaller_in_C (int val)
{
    int p, u, mij, ras = 0;
    p = 1, u = M_dis;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (B_dis[mij] < val) ras = mij, p = mij + 1;
        else u = mij - 1;
    }
    return ras;
}

int how_many_distinct_in_interval (int st, int dr)
{
    int p1 = last_smaller_in_C (st) + 1, p2 = last_smaller_in_C (dr);
    if (B_dis[p1] == st) p1 ++;
    if (p2 < p1) return 0;
    return p2 - p1 + 1;
}

int count_gaps (int st, int dr)
{
    return gaps[dr] - gaps[st - 1];
}

void solve (int pos)
{
    if (pos == 1) return ;
    if (prec[pos] != -1) solve (prec[pos]);
    else
    {
        for (int i=pos - 1; i>=1; i--)
            if (A[i] != -1 && A[i] < A[pos])
            {
                int intre, no_val = how_many_distinct_in_interval (A[i], A[pos]), no_gaps = count_gaps (i + 1, pos - 1);
                if (no_gaps < no_val) intre = no_gaps;
                else intre = no_val;
                if (1 + intre + dp[i] == dp[pos])
                {
                    int old = A[i];
                    for (int k=i+1; k<=pos; k++)
                    if (A[k] == -1)
                    {
                        if (!intre) break;
                        intre --;
                        for (int p=1; p<=M; p++)
                            if (!used[p] && B[p] > old && B[p] < A[pos])
                            {
                                old = A[k] = B[p], used[p] = 1;
                                break;
                            }
                    }
                    solve (i);
                    return ;
                }
            }
    }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

Read ();
for (int i=1; i<=N; i++)
    how[i] = N + 1;
how[1] = dp[1] = 1;
for (int i=1; i<=N; i++)
    C[i] = A[how[i]];
for (int i=2; i<=N; i++)
{
    if (A[i] != -1)
    {
        int p, u, mij, ras = 0;
        p = 1, u = N;
        while (p <= u)
        {
            mij = (p + u) >> 1;
            if (C[mij] < A[i]) ras = mij, p = mij + 1;
            else u = mij - 1;
        }
        dp[i] = ras + 1;
        prec[i] = how[ras];
        if (A[i] < C[ras + 1]) C[ras + 1] = A[i], how[ras + 1] = i;
        continue;
    }
    else
    {
        int pos = N;
        for (int j=M_dis; j>=1; j--)
        {
            while (C[pos] >= B_dis[j]) pos --;
            if (C[pos + 1] > B_dis[j]) C[pos + 1] = B_dis[j], how[pos + 1] = -1;
        }
    }
}
//if (N == 100002) return 0;
//printf ("%d\n", dp[N] - 2);
solve (N);
int j = 1;
for (int i=1; i<=N; i++)
    if (A[i] == -1)
    {
        while (used[j]) j++;
        A[i] = B[j], used[j] = 1;
    }
for (int i=2; i<N; i++)
    printf ("%d ", A[i]);
printf ("\n");
return 0;
}