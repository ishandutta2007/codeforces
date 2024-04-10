#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
   long long n;
   scanf("%I64d", &n);
   while((n%3LL) == 0)
        n /= 3;
    printf("%I64d", n/3LL+1);
    return 0;
}