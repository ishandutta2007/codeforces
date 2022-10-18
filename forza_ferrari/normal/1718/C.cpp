#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
#define int long long
int t,n,q,cnt,d[11],a[200001];
vector<int> v[11];
multiset<int> ans;
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
signed main()
{
    t=read();
    while(t--)
    {
        n=read(),q=read();
        for(int i=1;i<=cnt;++i)
            v[i].clear();
        cnt=0;
        int m=n;
        for(int i=2;i*i<=n;++i)
            if(m%i==0)
            {
                d[++cnt]=n/i;
                v[cnt].resize(d[cnt]);
                while(m%i==0)
                    m/=i;
            }
        if(m^1)
        {
            d[++cnt]=n/m;
            v[cnt].resize(d[cnt]);
        }
        ans.clear();
        for(int i=1;i<=n;++i)
        {
            a[i]=read();
            for(int j=1;j<=cnt;++j)
                v[j][i%d[j]]+=a[i];
        }
        for(int i=1;i<=cnt;++i)
            for(int j=0;j<d[i];++j)
                ans.emplace(d[i]*v[i][j]);
        cout<<*--ans.end()<<'\n';
        while(q--)
        {
            int x=read(),w=read();
            for(int i=1;i<=cnt;++i)
            {
                ans.erase(ans.find(d[i]*v[i][x%d[i]]));
                v[i][x%d[i]]-=a[x];
                v[i][x%d[i]]+=w;
                ans.emplace(d[i]*v[i][x%d[i]]);
            }
            a[x]=w;
            cout<<*--ans.end()<<'\n';
        }
    }
    return 0;
}