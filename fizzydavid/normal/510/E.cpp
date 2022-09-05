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
struct edge
{
    int to,cap,rev;
    bool f;
};
edge make_edge(int a,int b,int c,bool d)
{
    edge _;
    _.to=a;_.cap=b;_.rev=c;_.f=d;
    return _;
}
vector<edge>con[211];
void add_edge(int x,int y,int c)
{
    con[y].PB(make_edge(x,0,con[x].size(),0));
    con[x].PB(make_edge(y,c,con[y].size()-1,1));
}
inline int getval()
{
    int __res=0;bool __neg=0;
    char __c;__c=getchar();
    while(__c==' '||__c=='\n')__c=getchar();
    while(__c!=' '&&__c!='\n')
    {
        if(__c=='-')__neg=1;
        else __res=__res*10+__c-'0';
        __c=getchar();
    }
    if(__neg)__res=-__res;
    return __res;
}
int n,a[211];
bool isp[30011];
vector<int>odd,even,tmp;
vector<vector<int> >g;
void initialize()
{
    for(int i=2;i*i<=30000;i++)
    {
        if(!isp[i])
        {
            for(int j=i+i;j<=30000;j+=i)isp[j]=1;
        }
    }
}
bool used[211];
int dfs(int x,int t,int f)
{
    if(x==t)return f;
    used[x]=1;
    for(int i=0;i<con[x].size();i++)
    {
        if(!used[con[x][i].to]&&con[x][i].cap>0)
        {
            int c=dfs(con[x][i].to,t,min(f,con[x][i].cap));
            if(c>0)
            {
                con[x][i].cap-=c;
                con[con[x][i].to][con[x][i].rev].cap+=c;
                return c;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t)
{
    int res=0,f=0;
    while(true)
    {
        memset(used,0,sizeof(used));
        f=dfs(s,t,INF);
        if(f==0)return res;else res+=f;
    }
}
void dfs(int x)
{
    used[x]=1;tmp.PB(x);
    for(int i=0;i<con[x].size();i++)
    {
        edge &e=con[x][i];
        if((e.f&&e.cap==0||!e.f&&con[e.to][e.rev].cap==0)&&!used[e.to])
        {
            dfs(e.to);return;
        }
    }
}
int main()
{
    initialize();
    n=getval();
    for(int i=1;i<=n;i++)
    {
        a[i]=getval();
        if(a[i]&1)odd.PB(i),add_edge(0,i,2);else even.PB(i),add_edge(i,n+1,2);
    }
    for(int i=0;i<odd.size();i++)
    {
        for(int j=0;j<even.size();j++)
        {
            if(!isp[a[odd[i]]+a[even[j]]])add_edge(odd[i],even[j],1);
        }
    }
    if(max_flow(0,n+1)!=even.size()*2)
    {
        puts("Impossible");
    }
    else
    {
        memset(used,0,sizeof(used));
        used[0]=used[n+1]=1;
        for(int i=1;i<=n;i++)
        {
            if(!used[i])dfs(i),g.PB(tmp),tmp.clear();
        }
        printf("%d\n",g.size());
        for(int i=0;i<g.size();i++)
        {
            printf("%d ",g[i].size());
            for(int j=0;j<g[i].size();j++)printf("%d ",g[i][j]);
            puts("");
        }
    }
    return 0;
}