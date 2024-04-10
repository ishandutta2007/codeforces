#include<bits/stdc++.h>

using namespace std;

int N, M, p[1000009], p2[1000009];
const int mod = 1e9 + 7;

int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int main ()
{
scanf ("%d %d", &N, &M), p[0] = p2[0] = 1;
for (int i=1; i<=N; i++)
    p[i] = mul (p[i - 1], M), p2[i] = mul (p2[i - 1], 2 * M - 1);
int ans = p[N];
for (int P=1; P<=N; P++)
    adto (ans, mul (p[N - P + 1], p2[P - 1]));
printf ("%d\n", ans);
return 0;
}