#include<iostream>
#include<cstdio>
using namespace std;
long long t,x,y,ans;
inline int calc(int x,int l,int r)
{
    if(x<l)
        return x*(r-l+1);
    if(x>r)
        return (l+r)*(r-l+1)/2;
    return (l+x)*(x-l+1)/2+(r-x)*x;
}
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        ans=0;
        scanf("%lld%lld",&x,&y);
        for(register int i=2,j;i<=x&&i<=y+1;i=j+1)
        {
            j=min(x/(x/i),y+1);
            ans+=calc(x/i,i-2,j-2);
        }
        printf("%lld\n",ans);
    }
    /*for(register int b=1;b<=10;++b)
    {
        ans=0;
        for(register int a=1;a<=1000;++a)
            if(a/b==a%b)
                printf("%d %d\n",a,b);
    }*/
    return 0;
}