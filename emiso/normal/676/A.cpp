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

int main()
{
    int n,x,men,mai,ans;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&x);
        if(x == 1) men = i;
        if(x == n) mai = i;
    }

    if(mai < men) swap(mai,men);

    ans = abs(men-mai);
    if(men != 1) ans = max(ans,abs(mai-1));
    if(mai != n) ans = max(ans,abs(n-men));

    printf("%d\n",ans);
    return 0;
}