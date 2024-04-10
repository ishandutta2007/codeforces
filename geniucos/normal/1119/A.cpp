#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009;
int N, a[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
if (a[1] != a[N]) printf ("%d\n", N - 1);
else {
    int i = 1, j = N, x = a[1];
    while (a[i] == x) i ++;
    while (a[j] == x) j --;
    printf("%d\n", max(j - 1, N - i));
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/