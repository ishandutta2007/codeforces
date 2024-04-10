#include<bits/stdc++.h>

using namespace std;

const int maxV = 1e7 + 100, maxN = 4e5 + 100;
int N, a[maxN], b[maxN];

int brute (int N, int a[])
{
    int ans = 0;
    for (int i=1; i<=N; i++)
        for (int j=i + 1; j<=N; j++)
            ans ^= (a[i] + a[j]);
    return ans;
}

long long countSums (int lo, int hi)
{
    //[lo, hi)
    long long cnt = 0;
    int j = N + 1, k = N;
    for (int i=1; i<=N; i++)
    {
        while (j > 1 && a[i] + a[j - 1] >= lo)
            j --;
        while (k > 0 && a[i] + a[k] >= hi)
            k --;
        if (max (j, i + 1) <= k)
            cnt += k - max (j, i + 1) + 1;
    }
    return cnt;
}

int solve (int N, int b[])
{
    int ans = 0;
    for (int K=0; (1 << K) <= 2 * maxV; K++)
    {
        for (int i=1; i<=N; i++)
            a[i] = b[i] & ((1 << (K + 1)) - 1);
        sort (a + 1, a + N + 1);
        int curr = 1 << K;
        long long cnt = countSums (curr, 2 * curr) + countSums (3 * curr, 4 * curr);
        if (cnt & 1)
            ans |= 1 << K;
    }
    return ans;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &b[i]);
//printf ("%d\n", brute (N, b));
printf ("%d\n", solve (N, b));
//printf ("%d\n", brute (N, b));
return 0;
}