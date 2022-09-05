#include<bits/stdc++.h>

using namespace std;

int N, b[1000009];
long long a[1000009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &b[i]);
long long curr = 0;
for (int i=1; i<=N; i++)
{
    a[i] = curr + b[i];
    printf ("%I64d%c", a[i], " \n"[i == N]);
    if (a[i] > curr)
        curr = a[i];
}
return 0;
}