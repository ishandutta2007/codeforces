//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
#define input2(x,y) x=getval(),y=getval()
#define input3(x,y,z) x=getval(),y=getval(),z=getval()
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,m,p[100111][20],dis[100111],sum[100111];
vector<int>con[100111];
void init_dfs(int x,int pre,int d)
{
    dis[x]=d;sum[x]=1;
    for(int i=0;i<con[x].size();i++)
    {
        if(dis[con[x][i]]>0)continue;
        p[con[x][i]][0]=x;
        init_dfs(con[x][i],x,d+1);
        sum[x]+=sum[con[x][i]];
    }
}
int lca(int x,int y)
{
    if(dis[x]<dis[y])swap(x,y);
    for(int i=19;i>=0;i--)
    {
        if(p[x][i]!=-1&&dis[p[x][i]]>=dis[y])
        {
            x=p[x][i];
        }
    }
    if(x==y)return x;
    for(int i=19;i>=0;i--)
    {
        if(p[x][i]!=-1&&p[x][i]!=p[y][i])
        {
            x=p[x][i];
            y=p[y][i];
        }
    }
    return p[x][0];
}
int cal(int x)
{
    int ans=0;
    while(x/2>0)x/=2,ans++;
    return ans;
}
int find_p(int x,int k)
{
    while(k>0)
    {
        int t=k&(-k);
        x=p[x][cal(t)];
        k-=t;
    }
    return x;
}
void solve(int x,int y)
{
    if(x==y)
    {
        printf("%d\n",n);
        return;
    }
    if(dis[x]<dis[y])swap(x,y);
    int tmp=lca(x,y),d=dis[x]-dis[tmp]+dis[y]-dis[tmp];
//  cout<<"dis="<<d<<endl;
    if(d&1)puts("0");
    else if(dis[x]!=dis[y])
    {
        int t1=find_p(x,d/2),t2=find_p(x,d/2-1);
        printf("%d\n",sum[t1]-sum[t2]);
    }
    else
    {
        int t2=find_p(x,d/2-1),t3=find_p(y,d/2-1);
        printf("%d\n",n-sum[t2]-sum[t3]);
    }
}
int main()
{
    scanf("%d",&n);
    int x,y;
    for(int i=1;i<n;i++)scanf("%d%d",&x,&y),con[x].PB(y),con[y].PB(x);
    init_dfs(1,-1,1);
    for(int i=1;i<20;i++)for(int j=1;j<=n;j++)p[j][i]=p[p[j][i-1]][i-1];
    int m;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d",&x,&y);
        solve(x,y);
    }
    return 0;
}
/*
12
1 2
2 3
2 4
4 5
5 6
5 7
4 8
8 9
1 10
10 11
10 12
*/