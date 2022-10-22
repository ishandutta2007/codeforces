#include<cstdio>
#include<vector>
using namespace std;
int n,q,val[1005];
vector<int> vec[1005];
int getmod(int x)
{
    return ((x%2520)+2520)%2520;
}

int mem[1005][2530];
bool vis[1005][2530];

int cnt[1005];
vector<int> changed;
int calc(int p,int x)
{
    int Nowp=p,Nowx=x,res=0;
    do
    {
        x=getmod(x+val[Nowp]);
        Nowp=vec[Nowp][x%vec[Nowp].size()];
        if(cnt[Nowp]==0)
        {
            res++;
            changed.push_back(Nowp);
        }
        cnt[Nowp]++;
    }while(Nowp!=p || Nowx!=x);
    for(int i=0;i<changed.size();i++) cnt[changed[i]]=0;
    changed.clear();
    return res;
}
int dfs(int p,int x)
{
    if(mem[p][x]) return mem[p][x];
    if(vis[p][x]) return calc(p,x);
    vis[p][x]=true;
    return mem[p][x]=dfs(vec[p][(x+val[p])%vec[p].size()],getmod(x+val[p]));
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&val[i]);
        val[i]=getmod(val[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int m,x;
        scanf("%d",&m);
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&x);
            vec[i].push_back(x);
        }
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int p,x;
        scanf("%d%d",&p,&x);
        x=getmod(x);
        printf("%d\n",dfs(p,x));
    }
}