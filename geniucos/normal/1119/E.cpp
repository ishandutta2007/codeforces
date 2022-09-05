#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009, konst = 3;
int N;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
long long maxSoFar = 0, allSoFar = 0;
for (int i=0; i<N; i++)
{
    int x;
    scanf ("%d", &x);
    int toFix = (int) min((long long) x / 2, allSoFar - 3LL * maxSoFar);
    long long newMax = maxSoFar;
    for (int j=max(toFix - konst, 0); j<=toFix + konst && 2LL * j <= x; j++)
    {
        ///assume we take j pairs to match with some of the previous
        if (j > allSoFar) continue;
        long long curr = allSoFar - 3LL * maxSoFar;
        if (curr >= j) curr = j + maxSoFar + (x - 2 * j) / 3;
        else {
            curr = j - curr;
            if (curr % 3 == 0) curr /= 3;
            else curr /= 3, curr ++; ///this is how many triplets i destroy
            assert(curr <= maxSoFar);
            curr = maxSoFar - curr + j + (x - 2 * j) / 3;
        }
        if (curr > newMax)
            newMax = curr;
    }
    maxSoFar = newMax;
    allSoFar += x;
}
printf ("%I64d\n", maxSoFar);
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/