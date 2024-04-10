#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<set>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

long long A;

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%I64d", &A);
unsigned long long x = 810 % A;
for (int i=1; i<=17; i++)
    x = ((unsigned long long)1LL * x * 10) % A;
x ++;
if (x == A)
    x = 0;
long long rest = A - x;
if (rest == A)
    rest = 0;
printf ("%I64d %I64d\n", 1 + rest, (long long) 1000000000000000000LL + rest);

return 0;
}