#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009;
int N, M, K, ta, tb, a[maxN], b[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf("%d %d %d %d %d", &N, &M, &ta, &tb, &K);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
for (int i=1; i<=M; i++)
    scanf ("%d", &b[i]);
if (K >= N)
{
    printf("-1\n");
    return 0;
}
long long ans = -1;
int j = 1;
for (int i=1; i<=min(N, K + 1); i++)
{
    ///assume cancel first i - 1 flights
    while (b[j] < a[i] + ta && j <= M)
        j ++;
    int toCancel = K - (i - 1);
    if (j + toCancel > M)
    {
        printf("-1\n");
        return 0;
    }
    if (b[j + toCancel] > ans)
        ans = b[j + toCancel];
}
printf ("%I64d\n", ans + tb);
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/