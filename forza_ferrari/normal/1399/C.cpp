#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n,a[51],b[111],ans,sum;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=sum=0;
        memset(b,0,sizeof b);
        for(register int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            ++b[a[i]];
        }
        for(register int i=2;i<=n<<1;++i)
        {
            sum=0;
            for(register int j=1;j<=min(i-1,n);++j)
            {
                if(j>i-j)
                    break;
                if(j<i-j)
                    sum+=min(b[j],b[i-j]);
                if(j==i-j)
                    sum+=b[j]>>1;
            }
            ans=max(ans,sum);
        }
        printf("%d\n",ans);
    }
    return 0;
}