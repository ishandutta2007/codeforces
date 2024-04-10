#include<bits/stdc++.h>

using namespace std;

int x, N;
bool ap[1000009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

for (int i=0; i<=1000; i++)
    ap[i * i] = 1;
scanf ("%d", &N);
int maxi = -100000000;
while (N --)
{
    scanf ("%d", &x);
    if (x >= 0 && ap[x]) continue;
    if (x > maxi)
        maxi = x;
}
printf ("%d\n", maxi);
return 0;
}