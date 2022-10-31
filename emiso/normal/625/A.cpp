#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>

#define w1 while(1)
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

long long ans,a,b,c,n;

int main()
{
    scanf("%I64d %I64d %I64d %I64d",&n,&a,&b,&c);

    if(b > n || a <= b-c) {
        ans += (n/a);
    }

    else {
        ans = 1;
        n -= b;
        ans += (n/(b-c));
        n = n%(b-c);
        n += c;
        ans += (n/a);
    }

    printf("%I64d\n",ans);
    return 0;
}