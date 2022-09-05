#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009;
int N, sum[maxN];
char s[maxN];
long long ans = 0;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%s", s + 1), N = strlen(s + 1);
for (int i=1; i<=N; i++)
    sum[i] = sum[i - 1] + (i >= 2 && s[i] == s[i - 1] && s[i] == 'v');
for (int i=3; i + 2 <= N; i++)
    if (s[i] == 'o')
        ans += 1LL * sum[i - 1] * (sum[N] - sum[i]);
printf("%I64d\n", ans);
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/