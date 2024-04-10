#include<bits/stdc++.h>

using namespace std;

int N;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

long long ans = 1LL << 50;
scanf ("%d", &N);
for (int i=0; i<10; i++)
{
    long long val = i;
    for (int j=0; j<=12; j++)
    {
        if (val > N && val < ans) ans = val;
        val = 1LL * val * 10;
    }
}
printf ("%I64d\n", ans - N);
return 0;
}