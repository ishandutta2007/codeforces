#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int t,x,y,n;
struct node
{
    int a,b;
    bool operator <(const node &other) const
    {
        return a<other.a;
    }
}p[100001];
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&x,&y,&n);
        for(register int i=1;i<=n;++i)
            scanf("%lld",&p[i].a);
        for(register int i=1;i<=n;++i)
            scanf("%lld",&p[i].b);
        sort(p+1,p+n+1);
        bool flag=1;
        for(register int i=1;i<=n;++i)
        {
            int cnt=p[i].b/x+(p[i].b%x!=0);
            y-=cnt*p[i].a;
            if(y<=0&&i!=n)
            {
                puts("NO");
                flag=0;
                break;
            }
            if(i==n&&y+p[i].a<=0)
            {
                puts("NO");
                flag=0;
                break;
            }
        }
        if(flag)
            puts("YES");
    }
    return 0;
}