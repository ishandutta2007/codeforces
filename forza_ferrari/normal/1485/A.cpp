#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int t,a,b,ans;
inline int check(int x,int y)
{
    if(y==1)
        return 1<<30;
    int res=0;
    while(x)
    {
        x/=y;
        ++res;
    }
    return res;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans=1<<30;
        scanf("%d%d",&a,&b);
        if(a<b)
        {
            puts("1");
            continue;
        }
        for(register int i=0;i<=3000;++i)
            ans=min(ans,check(a,b+i)+i);
        printf("%d\n",ans);
    }
    return 0;
}