#include<bits/stdc++.h>

using namespace std;

int N, K, z[1000009], s[1000009];
char sir[1000009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n%s", &N, &K, sir + 1);
int R = 1, P = 1;
for (int i=2; i<=N; i++)
{
    if (R >= i)
        z[i] = min (z[i - P + 1], R - i + 1);
    while (i + z[i] <= N && sir[i + z[i]] == sir[z[i] + 1])
        z[i] ++;
    if (i + z[i] - 1 > R)
        R = i + z[i] - 1, P = i;
}
for (int i=K; i<=N; i+=K)
{
    int P = i / K;
    if (z[P + 1] < (K - 1) * P) continue;
    int maxL = min (z[i + 1], P);
    s[i] ++, s[i + maxL + 1] --;
}
for (int i=1; i<=N; i++)
{
    s[i] += s[i - 1];
    printf ("%d", (s[i] > 0));
}
printf ("\n");
return 0;
}