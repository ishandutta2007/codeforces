#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t,n,m,cnt[300001],pos[300001],a[300001],nxt[300001];
bool vis[300001];
vector<int> ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ans.clear();
        for(int i=1;i<=n;++i)
            cnt[i]=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            ++cnt[(i-a[i]+n)%n];
        }
        for(int k=0;k<n;++k)
        {
            if(cnt[k]<n-2*m)
                continue;
            for(int i=1;i<=n;++i)
            {
                vis[i]=0;
                pos[a[i]]=i;
            }
            for(int i=1;i<=n;++i)
                nxt[i]=pos[(i-1-k+n)%n+1];
            int res=n;
            for(int i=1;i<=n;++i)
                if(!vis[i])
                {
                    --res;
                    for(int j=i;!vis[j];j=nxt[j])
                        vis[j]=1;
                }
            if(res<=m)
                ans.push_back(k);
        }
        cout<<ans.size();
        for(auto i:ans)
            cout<<" "<<i;
        cout<<endl;
    }
    return 0;
}