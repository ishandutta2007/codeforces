#include<bits/stdc++.h>

using namespace std;

int N, K;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
printf ("%d\n", N + K - N % K);

return 0;
}