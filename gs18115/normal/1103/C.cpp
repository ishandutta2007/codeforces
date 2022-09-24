#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,M,K;
vector<LL>ans;
vector<LL>adj[256789];
LL dep[256789],par[256789];
bool chk[256789];
inline void PATH(LL x)
{
    cout<<"PATH\n"<<dep[x]+1<<endl;
    while(x!=0)
    {
        cout<<x+1<<' ';
        x=par[x];
    }
    cout<<1<<endl;
    exit(0);
    return;
}
inline void CYCLES(const vector<LL>&V)
{
    if(V.size()<K)
    {
        cout<<-1<<endl;
        exit(0);
    }
    cout<<"CYCLES";
    for(LL i=0;i<K;i++)
    {
        LL t=V[i];
        LL p1=adj[t][0],p2=adj[t][1];
        if(p1==par[t])
            p1=adj[t][2];
        else if(p2==par[t])
            p2=adj[t][2];
        if(dep[p1]>dep[p2])
            swap(p1,p2);
        if((dep[t]-dep[p2]+1)%3!=0)
        {
            cout<<'\n'<<dep[t]-dep[p2]+1<<'\n';
            while(t!=p2)
            {
                cout<<t+1<<' ';
                t=par[t];
            }
            cout<<p2+1;
        }
        else if((dep[t]-dep[p1]+1)%3!=0)
        {
            cout<<'\n'<<dep[t]-dep[p1]+1<<'\n';
            while(t!=p1)
            {
                cout<<t+1<<' ';
                t=par[t];
            }
            cout<<p1+1;
        }
        else
        {
            cout<<'\n'<<dep[p2]-dep[p1]+2<<'\n'<<t+1<<' ';
            while(p2!=p1)
            {
                cout<<p2+1<<' ';
                p2=par[p2];
            }
            cout<<p1+1;
        }
    }
    return;
}
void dfs(LL x)
{
    chk[x]=true;
    if(dep[x]*K>=N)
        PATH(x);
    LL i;
    bool flag=true;
    for(i=0;i<adj[x].size();i++)
    {
        if(chk[adj[x][i]])
            continue;
        flag=false;
        par[adj[x][i]]=x;
        dep[adj[x][i]]=dep[x]+1;
        dfs(adj[x][i]);
    }
    if(flag)
        ans.push_back(x);
    return;
}
LL s,e,i;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M>>K;
    for(i=0;i<M;i++)
    {
        cin>>s>>e;
        adj[--s].push_back(--e);
        adj[e].push_back(s);
    }
    par[0]=-1;
    dfs(0);
    CYCLES(ans);
    cout<<endl;
    return 0;
}