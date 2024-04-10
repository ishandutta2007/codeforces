#include<cstdio>
#include<bitset>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int cnt;
long long A, B;

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%I64d %I64d", &A, &B);
///pana in 2 ^ 60 - 1 adica 60 de biti
for (int a=1; a<=60; a ++)
    for (int b=0; a + b + 1 <= 60; b ++)
    {
        long long numar = 0;
        for (int i=0; i<a; i++)
            numar += 1LL << (b + 1 + i);
        for (int i=0; i<b; i++)
            numar += 1LL << i;
        cnt += (numar >= A && numar <= B);
    }
printf ("%d\n", cnt);
return 0;
}