#include<cstdio>
#include<vector>
using namespace std;
int n,m,t,val[200005],dep[200005];
bool flag,Twopart;
long long Sum1,Sum2;
vector<int> vec[200005];
void dfs(int x,int fa)
{
    dep[x]=dep[fa]+1;
    if(dep[x]%2==1) Sum1+=val[x];
    else Sum2+=val[x];
    for(auto &p : vec[x])
    {
        if(!dep[p]) dfs(p,x);
        else if((dep[p]-dep[x])%2==0) Twopart=false;
    }
}             
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&val[i]);
            dep[i]=0;
            vec[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            val[i]-=x;
        }
        for(int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        flag=true;
        for(int i=1;i<=n;i++)
        {
            if(dep[i]) continue;
            Sum1=Sum2=0;
            Twopart=true;
            dfs(i,0);
            if(Twopart && Sum1!=Sum2) flag=false;
            if(!Twopart && (Sum1+Sum2)%2!=0) flag=false; 
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}