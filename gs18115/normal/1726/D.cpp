#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
const int mxn=2e5+10;
vector<pi>adj[mxn];
bool chk[mxn];
int dep[mxn];
int col[mxn],pai[mxn];
vector<pi>back;
void dfs(int x,int p)
{
    chk[x]=1;
    for(pi&tt:adj[x])
    {
        int t=tt.fi;
        int id=tt.se;
        if(!chk[t])
            col[id]=0,pai[t]=id,dep[t]=dep[x]+1,dfs(t,x);
        else if(dep[t]>dep[x])
            col[id]=1,back.eb(t,x);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t-->0)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i++<n;)
            adj[i].clear(),chk[i]=0,dep[i]=0;
        back.clear();
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].eb(v,i);
            adj[v].eb(u,i);
        }
        dfs(1,0);
        vector<int>bvs;
        for(pi&t:back)
            bvs.eb(t.fi),bvs.eb(t.se);
        sort(all(bvs));
        bvs.erase(unique(all(bvs)),bvs.end());
        if(back.size()==3&&bvs.size()==3)
        {
            int mx=bvs[0];
            if(dep[bvs[1]]>dep[mx])
                mx=bvs[1];
            if(dep[bvs[2]]>dep[mx])
                mx=bvs[2];
            int rev=0;
            for(pi&t:adj[mx])
                if(col[t.se]==1)
                    rev=t.se;
            col[rev]=0,col[pai[mx]]=1;
        }
        for(int i=0;i<m;i++)
            cout<<col[i];
        cout<<endl;
    }
    return 0;
}