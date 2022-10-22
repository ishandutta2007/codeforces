#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,h[200005],Fa[200005],E[200005];
vector<int> Edge[200005];
long long ans;
void dfs(int x,int pre)
{
    Fa[x]=pre;
    for(auto &p : Edge[x])
    {
        if(p!=Fa[x]) dfs(p,x);
    }
}

int Maxn;
void FindMax(int x)
{
    if(E[x]>E[Maxn]) Maxn=x;
    for(auto &p : Edge[x])
    {
        if(p!=Fa[x]) FindMax(p);
    }
}

int MaxSon[200005];
void GetE(int x)
{
    MaxSon[x]=x;
    for(auto &p : Edge[x])
    {
        if(p==Fa[x]) continue;
        GetE(p);
        if(E[MaxSon[p]]>E[MaxSon[x]]) MaxSon[x]=MaxSon[p];
    }
    if(h[x]>E[MaxSon[x]]) E[MaxSon[x]]=h[x];
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
    }
    if(n==2)
    {
        printf("%d\n",max(h[1],h[2])*2);
        return 0;
    }
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        Edge[x].push_back(y);
        Edge[y].push_back(x);
    }
    int Root=1;
    while(Edge[Root].size()==1) Root++;
    dfs(Root,0);
    GetE(Root);
    FindMax(Root);
    int tmp=Maxn;
    vector<int> Chain;
    while(tmp!=Root) 
    {
        Chain.push_back(tmp);
        tmp=Fa[tmp];
    }
    Chain.push_back(Root);
    reverse(Chain.begin(),Chain.end());
    int Sec=0;
    for(int i=0;i<Chain.size();i++)
    {
        int Now=Chain[i],Nxt=0;
        if(Chain.size()!=i+1) Nxt=Chain[i+1];
        for(auto &p : Edge[Now])
        {
            if(p==Nxt || p==Fa[Now]) continue;
            Maxn=0;
            FindMax(p);
            Sec=max(Sec,E[Maxn]);
        }
        if(Sec<h[Now]) 
        {
            ans+=h[Now]-Sec;
            Sec=h[Now];
        } 
    }
    for(int i=1;i<=n;i++) ans+=E[i];
//    for(int i=1;i<=n;i++) printf("E %d = %d\n",i,E[i]);
    printf("%lld\n",ans);
}