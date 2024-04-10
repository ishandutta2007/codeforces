#include<bits/stdc++.h>

using namespace std;

long long N, ans;
char c;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%I64d%c", &N, &c);
if (c >= 'd') ans = 'f' - c;
else ans = 3 + c - 'a';
ans ++;
long long K = (N - 1) / 4;
ans += (K * 2LL + 1 - (N % 2)) * 6LL;
if (N % 4 <= 2 && N % 4 >= 1) N -= 1;
else N -= 3;
ans += N;
printf ("%I64d\n", ans);

return 0;
}