#include<bits/stdc++.h>

using namespace std;

int N, a, b, c;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &a, &b, &c);
if (a > b) swap(a, b);
if (b > a + 1) b = a + 1;
printf ("%I64d\n", a + b + 2LL * c);

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/