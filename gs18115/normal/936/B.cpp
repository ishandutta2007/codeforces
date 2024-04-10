#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
bool w[234567];
LL chk[234567];
bool draw;
LL N,e;
LL par[234567];
vector<LL>adj[234567];
vector<LL>V;
void dfs(LL x)
{
    if(w[x])
    {
        cout<<"Win"<<endl;
        V.push_back(x);
        while(x!=e)
        {
            x=par[x];
            V.push_back(x);
        }
        while(!V.empty())
        {
            cout<<V.back()%N+1<<' ';
            V.pop_back();
        }
        cout<<endl;
        exit(0);
    }
    chk[x]=1;
    for(LL i=0;i<adj[x].size();i++)
    {
        if(chk[adj[x][i]]==0)
        {
            par[adj[x][i]]=x;
            dfs(adj[x][i]);
        }
        else if(chk[adj[x][i]]==1)
            draw=true;
    }
    chk[x]=2;
    return;
}
LL M,i,j;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    for(i=0;i<N;i++)
    {
        cin>>M;
        if(M==0)
            w[i+N]=true;
        for(j=0;j<M;j++)
        {
            cin>>e;
            adj[i].push_back(--e+N);
            adj[i+N].push_back(e);
        }
    }
    cin>>e;
    dfs(--e);
    if(draw)
        cout<<"Draw"<<endl;
    else
        cout<<"Lose"<<endl;
    return 0;
}