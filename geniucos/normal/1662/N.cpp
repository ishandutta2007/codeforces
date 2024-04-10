#include<bits/stdc++.h>

using namespace std;

const int maxN = 1509;
int N, a[maxN][maxN], lin[maxN * maxN], col[maxN * maxN], cntL[maxN], cntC[maxN];
long long ans;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
        scanf ("%d", &a[i][j]),
        lin[a[i][j]] = i, col[a[i][j]] = j;
for (int i=1; i<=N * N; i++)
    ans += 1LL * cntL[lin[i]] * cntC[col[i]],
    cntL[lin[i]] ++, cntC[col[i]] ++;
long long all = 1LL * N * (N - 1) / 2;
ans = 2LL * all * all - ans;
printf ("%I64d\n", ans);
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/