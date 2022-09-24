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
bool chk[10][10];
vector<pi>cav[10][10];
int ans;
int k;
void calc(int id)
{
    if(id>k)
    {
        ans++;
        return;
    }
    for(int i=0;i++<id;)
    {
        if(chk[id][i])
            continue;
        vector<pi>chan;
        for(pi&t:cav[id][i])
            if(!chk[t.fi][t.se])
                chk[t.fi][t.se]=1,chan.eb(t);
        calc(id+1);
        for(pi&t:chan)
            chk[t.fi][t.se]=0;
    }
    return;
}
vector<pi>adj[200010];
vector<pi>in[200010];
int deg[200010];
int nxt[200010][10];
int cnt[10][10];
bool cant[10][10][10][10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].eb(v,w);
    }
    for(int i=0;i++<n;)
    {
        sort(all(adj[i]),[](const pi&x,const pi&y){return x.se<y.se;});
        deg[i]=adj[i].size();
        for(int j=0;j<deg[i];j++)
            nxt[i][j+1]=adj[i][j].fi;
        for(int j=0;j++<deg[i];)
            in[nxt[i][j]].eb(i,j);
    }
    for(int i=0;i++<n;)
    {
        for(int j=0;j++<k;)
            for(int l=0;l++<j;)
                cnt[j][l]=0;
        for(pi&t:in[i])
            cnt[deg[t.fi]][t.se]++;
        vector<vector<int> >one(k+1);
        for(int j=0;j++<k;)
        {
            for(int l=0;l++<j;)
            {
                if(cnt[j][l]>1)
                    chk[j][l]=1;
                else if(cnt[j][l]==1)
                    one[j].eb(l);
            }
        }
        for(int j=0;j++<k;)
            for(int l=j;l++<k;)
                for(int&t1:one[j])
                    for(int&t2:one[l])
                        cant[j][t1][l][t2]=1;
    }
    for(int i=0;i++<k;)
        for(int j=0;j++<i;)
            for(int l=i;l++<k;)
                for(int m=0;m++<l;)
                    if(cant[i][j][l][m])
                        cav[i][j].eb(l,m);
    calc(1);
    cout<<ans<<endl;
    return 0;
}