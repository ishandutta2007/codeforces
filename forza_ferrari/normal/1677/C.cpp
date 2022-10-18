#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int t,n,val[100001],pos[100001],cnt;
long long ans;
bool vis[100001];
vector<int> v;
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
inline bool cmp(int x,int y)
{
    return x>y;
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
            val[i]=read();
            vis[i]=0;
        }
        for(int i=1;i<=n;++i)
            pos[read()]=i;
        v.clear();
        for(int i=1;i<=n;++i)
            if(!vis[i])
            {
                cnt=0;
                for(int j=i;!vis[j];j=pos[val[j]])
                {
                    ++cnt;
                    vis[j]=1;
                }
                v.emplace_back(cnt);
            }
        sort(v.begin(),v.end(),cmp);
        int sum=n-1;
        for(auto i:v)
        {
            for(int j=2;j<=i;j+=2,sum-=2)
                ans+=sum<<1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}