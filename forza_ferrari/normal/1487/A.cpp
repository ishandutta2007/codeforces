#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,sum,minn;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        minn=1<<30;
        sum=0;
        for(register int i=1;i<=n;++i)
        {
            int x;
            scanf("%d",&x);
            if(x==minn)
                ++sum;
            if(x<minn)
            {
                minn=x;
                sum=1;
            }
        }
        printf("%d\n",n-sum);
    }
    return 0;
}