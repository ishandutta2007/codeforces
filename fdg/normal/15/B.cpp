#include <fstream>
#include <cstdio>

//#define dat cin
//#define sol cout
#define ll long long

using namespace std;

ll peretun(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3,ll x4,ll y4)
{
        if (x2>x3||y2>y3) return 0;
        return (x3-x2+1)*(y3-y2+1);
}

int main()
{
        int t;
        scanf("%d",&t);
        while(t--)
        {
                ll n,m,x1,y1,x2,y2;
                scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&m,&n,&y1,&x1,&y2,&x2);
                if (y1>y2)
                {
                        swap(x1,x2);
                        swap(y1,y2);
                }
                if (x2<x1) x2+=2*(x1-x2);
                x2-=(x1-1);
                x1=1;
                y2-=(y1-1);
                y1=1;
                ll x3=n-(x2-x1),y3=m-(y2-y1),x4=n,y4=m;
                ll ans=n*m-((x3-x1+1)*(y3-y1+1)+(x4-x2+1)*(y4-y2+1)-peretun(x1,y1,x2,y2,x3,y3,x4,y4));
                printf("%I64d\n",ans);
        }
        return 0;
}