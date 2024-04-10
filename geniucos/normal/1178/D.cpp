#include<bits/stdc++.h>

using namespace std;

int N, M;
bool cr[2022];

bool solve(int N) {
    for (int x=0; x<=N / 2; x++)
        if (cr[N + x] == 0)
        {
            printf("%d\n", N + x);
            for (int i=1; i<N; i++)
                printf("%d %d\n", i, i + 1);
            printf("%d 1\n", N);
            for (int i=1; i<=x; i++)
                printf("%d %d\n", i, i + N / 2);
            return 1;
        }
    return 0;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

for (int i=2; i<=2000; i++)
    if (cr[i] == 0)
        for (int j=i * i; j<=2000; j+=i)
            cr[j] = 1;
scanf("%d", &N);
assert(solve(N));
return 0;
}