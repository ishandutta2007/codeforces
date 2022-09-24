#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define semicolon 
#define ryan bear
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf=1e18;
//Tarjan's algorithm
int nc;
int disc[1000010];
int scc[1000010];
vector<int>adj[1000010];
vector<int>stk;
vector<vector<int> >scv;
int dfs(int x)
{
    int ret=disc[x]=++nc;
    stk.eb(x);
    for(int t:adj[x])
    {
        if(scc[t]>0)
            continue;
        if(disc[t]>0)
            ret=min(ret,disc[t]);
        else
            ret=min(ret,dfs(t));
    }
    if(ret==disc[x])
    {
        scv.eb(vector<int>());
        int t=-1;
        while(t!=x)
        {
            t=stk.back();
            stk.pop_back();
            scc[t]=scv.size();
            scv.back().eb(t);
        }
    }
    return ret;
}
int t,n,m,i;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t-->0)
    {
        cin>>n>>m;
        scv.clear();
        nc=0;
        for(i=0;i++<n;)
            scc[i]=disc[i]=0,adj[i].clear();
        for(i=0;i<m;i++)
        {
            int s,e;
            cin>>s>>e;
            adj[s].eb(e);
        }
        for(i=0;i++<n;)
            if(disc[i]==0)
                dfs(i);
        if(scv.size()==1)
        {
            cout<<"No\n";
            continue;
        }
        for(i=0;i<scv.size();i++)
        {
            int f=0;
            for(int j:scv[i])
                for(int k:adj[j])
                    if(scc[k]!=i+1)
                        f=1;
            if(f==0)
                break;
        }
        cout<<"Yes\n";
        cout<<scv[i].size()<<' '<<n-scv[i].size()<<'\n';
        for(int j=0;j++<n;)
            if(scc[j]==i+1)
                cout<<j<<' ';
        cout<<'\n';
        for(int j=0;j++<n;)
            if(scc[j]!=i+1)
                cout<<j<<' ';
        cout<<'\n';
    }
    cout<<endl;
    return 0;
}