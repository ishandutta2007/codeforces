#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int n,m,p,w,pos[6001];
vector<int> v[3001];
multiset<int> s;
long long ans,sum;
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
inline auto solve(int x)
{
    auto it=s.upper_bound(x);
    for(int i=1;i<=w;++i)
    {
        if(it==s.begin())
            return it;
        --it;
    }
    return it;
}
int main()
{
    n=read(),m=read(),p=read(),w=read();
    for(int i=1;i<=p;++i)
    {
        int x=read(),y=read();
        v[x].emplace_back(y);
    }
    for(int i=1;i<=n;++i)
        sort(v[i].begin(),v[i].end());
    for(int i=1;i<=n;++i)
    {
        sum=0;
        s.clear();
        for(int j=1;j<=w+1;++j)
        {
            s.emplace(0);
            s.emplace(m+1);
        }
        for(int j=i;j<=n;++j)
        {
            int tot=0;
            for(int k:v[j])
            {
                auto l=s.emplace(k),r=l;
                for(int cnt=w;cnt>=0;--cnt)
                    pos[cnt]=*(l--);
                for(int cnt=w+1;cnt<=w+w;++cnt)
                {
                    pos[cnt]=*(++r);
                    sum+=1ll*(pos[cnt]-pos[cnt-1])*(pos[cnt-w]-pos[cnt-w-1]);
                }
            }
            ans+=sum;
        }
    }
    cout<<ans<<'\n';
    return 0;
}