#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,m,t[200005],u[200005],v[200005];

class DSU
{
    public:
    int F[400005];
    void Init()
    {
        for(int i=1;i<=2*n;i++) F[i]=i;
    }
    int Find(int x)
    {
        return F[x]==x ? x : F[x]=Find(F[x]);
    }
    void Merge(int x,int y)
    {
        if(Find(x+n)!=Find(y)) F[Find(x+n)]=Find(y);
        if(Find(x)!=Find(y+n)) F[Find(x)]=Find(y+n);
    }
    bool Error()
    {
        for(int i=1;i<=n;i++) if(Find(i)==Find(i+n)) return true;
        return false;
    }
}D;

int Dir[200005]; // 0:L 1:R

int In[200005];
vector<int> Edge[200005];
void AddEdge(int x,int y)
{
    Edge[x].push_back(y);
    In[y]++;
}

queue<int> Q;
int cnt,pos[200005];

int main()
{
    scanf("%d%d",&n,&m);
    D.Init();
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&t[i],&u[i],&v[i]);
        D.Merge(u[i],v[i]);     
    }
    if(D.Error())
    {
        printf("NO\n");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(D.Find(i)==i) continue;
        if(D.Find(i)<=n) Dir[i]=Dir[D.Find(i)];
        else Dir[i]=Dir[D.Find(i)-n]^1;
    }
    for(int i=1;i<=m;i++)
    {
        if(Dir[u[i]]==0 && t[i]==1) AddEdge(u[i],v[i]);
        if(Dir[u[i]]==1 && t[i]==1) AddEdge(v[i],u[i]);
        if(Dir[u[i]]==0 && t[i]==2) AddEdge(v[i],u[i]);
        if(Dir[u[i]]==1 && t[i]==2) AddEdge(u[i],v[i]);
    }
    for(int i=1;i<=n;i++) if(In[i]==0) Q.push(i);
    while(!Q.empty())
    {
        int Now=Q.front();
        Q.pop();
        pos[Now]=++cnt;
        for(auto &p : Edge[Now])
        {
            In[p]--;
            if(In[p]==0) Q.push(p);
        }
    }
    bool Empty=true;
    for(int i=1;i<=n;i++) if(In[i]) Empty=false;
    if(!Empty)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for(int i=1;i<=n;i++)
    {
        printf("%c %d\n",(Dir[i]==0 ? 'L' : 'R'),pos[i]);
    }
}