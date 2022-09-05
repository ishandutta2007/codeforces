#include<bits/stdc++.h>

using namespace std;

int N, M, c[1009][1009], bell[1009];
char sir[60][1009];
const int mod = 1e9 + 7;
long long v[1009];

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &M, &N);
c[0][0] = 1;
for (int i=1; i<=M; i++)
{
    c[i][0] = 1;
    for (int j=1; j<=i; j++)
        c[i][j] = add (c[i - 1][j - 1], c[i - 1][j]);
}
bell[0] = bell[1] = 1;
for (int i=1; i<M; i++)
    for (int j=0; j<=i; j++)
        adto (bell[i + 1], mul (c[i][j], bell[j]));
for (int i=1; i<=N; i++)
{
    gets (sir[i] + 1);
    for (int j=1; j<=M; j++)
        sir[i][j] -= '0';
}
for (int j=1; j<=M; j++)
{
    v[j] = 0;
    for (int i=1; i<=N; i++)
        if (sir[i][j])
            v[j] |= 1LL << i;
}
sort (v + 1, v + M + 1);
int ans = 1;
for (int i=1; i<=M; i++)
{
    int j = i;
    for (; j<=M; j++)
        if (v[j] != v[i]) break;
    j --;
    ///[i, j]
    ans = mul (ans, bell[j - i + 1]);
    i = j;
}
printf ("%d\n", ans);
return 0;
}