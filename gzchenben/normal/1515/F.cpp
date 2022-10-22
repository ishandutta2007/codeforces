#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,k,u[300005],v[300005];
long long a[300005];
bool flag[300005];
vector<pair<int,int> > vec[300005];//pair<To,EdgeID>

int f[300005];
int Find(int x)
{
    return f[x]==x ? x : f[x]=Find(f[x]);
}
void Merge(int x,int y)
{
    x=Find(x); 
    y=Find(y);
    if(x==y) return;
    if(vec[x].size()>vec[y].size()) swap(x,y);
    for(int i=0;i<vec[x].size();i++)
    {
        vec[y].push_back(vec[x][i]); 
    }
    a[y]=a[x]+a[y]-k;
    f[x]=y;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
        f[i]=i;
    }
    if(sum<(long long)k*(n-1)) 
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        vec[u[i]].push_back(make_pair(v[i],i));
        vec[v[i]].push_back(make_pair(u[i],i));
    }
    for(int i=1;i<=n;i++)
    {
        if(f[i]!=i) continue;
        int x=i;
        while(a[x]>=k)
        {
            while(vec[x].size() && Find(vec[x][vec[x].size()-1].first)==x) vec[x].pop_back();
            if(!vec[x].size()) break;
            printf("%d\n",vec[x][vec[x].size()-1].second);
            flag[vec[x][vec[x].size()-1].second]=true;
            Merge(x,vec[x][vec[x].size()-1].first);
            x=Find(x);
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(!flag[i] && Find(u[i])!=Find(v[i]))
        {
            f[Find(u[i])]=Find(v[i]);
            printf("%d\n",i);
        } 
    }
}