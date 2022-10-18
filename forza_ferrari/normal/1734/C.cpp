#include<iostream>
#include<cstdio>
using namespace std;
int t,n;
bool a[1000001],vis[1000001];
long long ans;
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
        ans=0;
        n=read();
        for(int i=1;i<=n;++i)
        {
            vis[i]=0;
            char c=getchar();
            while(c!='0'&&c!='1')
                c=getchar();
            a[i]=c-'0';
        }
        for(int i=1;i<=n;++i)
            for(int j=i;j<=n;j+=i)
            {
                if(a[j])
                    break;
                if(!vis[j])
                {
                    vis[j]=1;
                    ans+=i;
                }
            }
        cout<<ans<<'\n';
    }
    return 0;
}