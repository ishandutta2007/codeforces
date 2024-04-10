//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,m;
pair<int,int> a[200111];
vector<int>con[200111];
int ans[100111],asz;
bool live[200111],vis[200111];
void dfs(int x)
{
    if(live[x])
    {
        cout<<"-1"<<endl;
        exit(0);
    }
    if(vis[x])return;
    vis[x]=1;live[x]=1;
    for(int i=0;i<con[x].size();i++)dfs(con[x][i]);
    live[x]=0;
    if(x<=m)ans[asz++]=x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int id=m;int x,sz;
    for(int i=1;i<=n;i++)
    {
        sz=0;
        for(int j=1;j<=m;j++)
        {
            cin>>x;
            if(x!=-1)a[sz++]=MP(x,j);
        }
        sort(a,a+sz);
        int pre=-1,tmp=-1,nxt=-1;
        for(int j=0;j<sz;j++)
        {
            if(tmp!=a[j].FF)
            {
                tmp=a[j].FF;
                if(nxt!=-1)pre=nxt;
                if(pre!=-1)con[pre].PB(a[j].SS);
                nxt=++id;
                con[a[j].SS].PB(nxt);
            }
            else
            {
                con[pre].PB(a[j].SS);
                con[a[j].SS].PB(nxt);
            }
        }
    }
    for(int i=1;i<=id;i++)dfs(i);
    for(int i=asz-1;i>=0;i--)cout<<ans[i]<<" ";cout<<endl;
    return 0;
}