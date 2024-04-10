#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
#define ll long long
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        ll x,y,xy1,x1,y2,xy2,x2,y1,ans=0;
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&x,&y,&xy1,&y1,&x2,&xy2,&y2,&x1);
        y1=min(y1,xy1+x2);
        x1=min(x1,xy1+y2);
        y2=min(y2,xy2+x1);
        x2=min(x2,xy2+y1);
        if(x>=0 && y>=0)
        {
            ans=x*x1+y*y1;
            if(x>y) ans=min(ans,xy1*y+x1*(x-y));
            else ans=min(ans,xy1*x+y1*(y-x));
        }
        else if(x<=0 && y<=0)
        {
            x=-x,y=-y;
            ans=x*x2+y*y2;
            if(x>y) ans=min(ans,xy2*y+x2*(x-y));
            else ans=min(ans,xy2*x+y2*(y-x));
        }
        else if(x<=0 && y>=0) ans=x2*-x+y1*y;
        else ans=x1*x+y2*-y;
        printf("%lld\n",ans);
    }
    return 0;
}