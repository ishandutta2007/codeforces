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

long long loabs(long long a,long long b) {
    if(a-b < 0) return b-a;
    return a-b;
}

int main()
{
    long long n,act=0,ans=0,x;
    scanf("%I64d",&n);
    for(int i=0;i<n;i++) {
        scanf("%I64d",&x);
        ans += loabs(x,act);
        act = x;
    }
    printf("%I64d\n",ans);
    return 0;
}