#include<iostream>
#include<cstdio>
using namespace std;
int t,n,x,y,ans,maxn;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&x,&y);
        ans=maxn=1<<30;
        int f=0;
        if(n==2)
        {
            printf("%d %d\n",x,y);
            continue;
        }
        int p=y-x;
        for(register int i=p;i>=1;--i)
        {
            if(p%i)
                continue;
            f=max(x%i? x%i:i,x-i*(n-(p/i)-1));
            if(f>x)
                continue;
            if(f+i*(n-1)>=y&&f+i*(n-1)<maxn)
            {
                maxn=f+i*(n-1);
                ans=i;
                if(maxn==y)
                    break;
            }
        }
        for(register int i=max(x%ans? x%ans:ans,x-ans*(n-(p/ans)-1));i<=maxn;i+=ans)
            printf("%d ",i);
        puts("");
    }
    return 0;
}