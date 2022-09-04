#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef long long ll;
main()
{
    ll num[1000000];
    int i,maxn,ans=0;
    num[1]=2;
    for(i=2;;i++)
    {
        num[i]=num[i-1]+3*i-1;
        if(num[i]>1e12)
            break;
    }
    maxn=i-1;
    ll n;
    scanf("%I64d",&n);
    for(i=1;i<maxn;i++)
    {
        if((n+i)%3!=0)
            continue;
        if(n>=num[i])
            ans++;

    }
    printf("%d\n",ans);
    return 0;
}