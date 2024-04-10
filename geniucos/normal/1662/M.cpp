#include<bits/stdc++.h>

using namespace std;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    int N, M;
    scanf ("%d %d", &N, &M);
    int maxR = 0, maxW = 0;
    for (int i=1; i<=M; i++) {
        int r, w;
        scanf ("%d %d", &r, &w);
        if (r > maxR) maxR = r;
        if (w > maxW) maxW = w;
    }
    if (maxR + maxW > N) printf ("IMPOSSIBLE\n");
    else {
        maxW = N - maxR;
        while (maxR --) printf ("R");
        while (maxW --) printf ("W");
        printf("\n");
    }
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/