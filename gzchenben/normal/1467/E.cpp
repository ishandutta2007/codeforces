#include<cstdio>
#include<vector>
#include<map>
using namespace std;
int n,a[200005],maxn,ans,cnt[200005],sum[200005],dif[200005],f[200005],mpmax;
vector<int> vec[200005];
map<int,int> mp;
void dfs1(int x,int fa)
{
    int tmp=cnt[a[fa]];
    cnt[a[x]]++;
    for(int i=0;i<vec[x].size();i++)
    {
        if(vec[x][i]==fa) continue;
        dfs1(vec[x][i],x);
    }
    f[x]=cnt[a[fa]]-tmp;
    int S=1;
    for(int i=0;i<vec[x].size();i++)
    {
        if(vec[x][i]==fa) continue;
        S+=f[vec[x][i]];
        if(f[vec[x][i]]>0) maxn++,dif[vec[x][i]]++;
    }
    if(S!=sum[a[x]]) dif[x]--;
}
void dfs2(int x,int fa)
{
    dif[x]+=dif[fa];
    for(int i=0;i<vec[x].size();i++)
    {
        if(vec[x][i]==fa) continue;
        dfs2(vec[x][i],x);
    }
    if(dif[x]==maxn) ans++;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(mp[a[i]]==0) mp[a[i]]=++mpmax;
        a[i]=mp[a[i]];
        sum[a[i]]++;
    }
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0);
    printf("%d\n",ans);
}