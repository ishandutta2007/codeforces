#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,ans;
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
int main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read();
        ans=0;
        int l=-2e9,r=2e9;
        for(int i=1;i<=n;++i)
        {
            int w=read();
            l=max(l,w-m);
            r=min(r,w+m);
            if(l>r)
            {
                l=w-m;
                r=w+m;
                ++ans;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}