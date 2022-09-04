#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
main()
{
    int n;
    long long int binary[64],now[64],l,m,i,ans;
    for(i=0;i<64;i++)
    binary[i]=pow(2,i);
    scanf("%d",&n);
    while(n--)
    {
    for(i=0;i<64;i++)
    now[i]=0;
    scanf("%I64d %I64d",&l,&m);
    ans=l;
    for(i=0;pow(2,i)<l;i++);
    for(;i>=0;l%=binary[i],i--)
    now[i]=l/binary[i];
    for(i=0;pow(2,i)<m;i++)
    if(now[i]==0&&ans+binary[i]<=m)
        ans+=binary[i];
        printf("%I64d\n",ans);
    }
}