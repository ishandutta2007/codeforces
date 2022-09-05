#include<bits/stdc++.h>

using namespace std;

int N, p[100009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
if (N % 4 > 1)
{
    printf ("-1\n");
    return 0;
}
p[N / 2 + 1] = N / 2 + 1;
for (int i=1; i<=N / 2; i+=2)
    p[i] = i + 1, p[i + 1] = N - i + 1, p[N - i + 1] = N - i, p[N - i] = i;
for (int i=1; i<=N; i++)
    printf ("%d ", p[i]);
printf ("\n");
return 0;
}