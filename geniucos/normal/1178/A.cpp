#include<bits/stdc++.h>

using namespace std;

const int maxN = 109;
int N, a[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
int nr = 0;
long long s = 0, coal = 0;
for (int i=1; i<=N; i++) {
    scanf ("%d", &a[i]);
    s += a[i];
    if (i == 1 || a[1] >= 2 * a[i])
        coal += a[i], nr ++;
}
if (coal <= s - coal) {
    printf("0\n");
    return 0;
}
printf("%d\n", nr);
for (int i=1; i<=N; i++)
    if (i == 1 || a[1] >= 2 * a[i])
        printf("%d ", i);
printf("\n");
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/