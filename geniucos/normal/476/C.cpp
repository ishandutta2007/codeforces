#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>

using namespace std;

int suma, C, A, B, sumr, mod;

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);
scanf ("%d %d", &A, &B);
mod = 1000000007;
suma = (1LL*A*(A+1)/2)%mod;
C = ((long long)A + 1LL*B*suma)%mod;
sumr = ((long long)1LL*B*(B-1)/2)%mod;
printf ("%I64d\n", (1LL*sumr*C)%mod);
return 0;
}