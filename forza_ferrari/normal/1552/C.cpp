#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t,n,m,p[201],cnt[101],ans;
vector<int> v;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        v.clear();
        for(int i=1;i<=n+n;++i)
            p[i]=0;
        ans=0;
        for(int i=1;i<=m;++i)
        {
            int x,y;
            cin>>x>>y;
            if(x>y)
                x^=y^=x^=y;
            for(int j=x+1;j<y;++j)
                if(p[j])
                    cnt[p[j]]^=1;
            for(int j=1;j<=n;++j)
            {
                ans+=cnt[j];
                cnt[j]=0;
            }
            p[x]=p[y]=i;
        }
        for(int i=1;i<=n+n;++i)
            if(!p[i])
                v.emplace_back(i);
        for(int i=0,tot=m;i<n-m;++i)
        {
            for(int j=v[i]+1;j<v[i+n-m];++j)
                if(p[j])
                    cnt[p[j]]^=1;
            for(int j=1;j<=n;++j)
            {
                ans+=cnt[j];
                cnt[j]=0;
            }
            p[v[i]]=p[v[i+n-m]]=++tot;
        }
        cout<<ans<<'\n';
    }
    return 0;
}