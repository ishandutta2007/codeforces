#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,d[200001],p[200001],cnt,node;
bool vis[200001];
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
        cnt=n;
        node=1;
        for(int i=1;i<=n;++i)
            d[i]=vis[i]=0;
        for(int i=1;i<n;++i)
            ++d[read()],++d[read()];
        for(int i=1;i<=n;++i)
        {
            p[i]=read();
            if(d[node]<d[i])
                node=i;
        }
        if(d[node]!=n-1)
        {
            cout<<"Alice\n";
            continue;
        }
        if((m==node||p[node]==m)&&p[node]!=node)
        {
            cout<<"Bob\n";
            continue;
        }
        for(int i=1;i<=n;++i)
            if(!vis[i])
            {
                --cnt;
                for(int j=i;!vis[j];j=p[j])
                    vis[j]=1;
            }
        if(cnt<=1&&p[m]==m)
        {
            cout<<"Alice\n";
            continue;
        }
        cout<<((cnt+(m!=node))&1? "Alice":"Bob")<<'\n';
    }
    return 0;
}