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
const int bucket=450;
int n,m;
vector<pair<int,int> >e[100111];
struct DSU
{
    int p[100111];
    DSU(){for(int i=1;i<=100000;i++)p[i]=i;}
    int Find(int x)
    {
        if(x==p[x])return x;
        return p[x]=Find(p[x]);
    }
    void Union(int x,int y){p[Find(x)]=Find(y);}
}d;
vector<int>temp[100111],appear[100111];
vector<vector<int> >comp;
vector<int>big;
bool used[100111];
int bigid[100111],query[450][100111];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;int x,y,c;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>c;
        e[c].PB(MP(x,y));
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<e[i].size();j++)d.Union(e[i][j].FF,e[i][j].SS);
        for(int j=0;j<e[i].size();j++)
        {
            int x=e[i][j].FF,y=e[i][j].SS;
            if(!used[x])temp[d.Find(x)].PB(x),used[x]=1;
            if(!used[y])temp[d.Find(y)].PB(y),used[y]=1;
        }
        for(int j=0;j<e[i].size();j++)
        {
            int x=e[i][j].FF,y=e[i][j].SS;
            if(temp[x].size()>0)comp.PB(temp[x]),temp[x].clear();
            if(temp[y].size()>0)comp.PB(temp[y]),temp[y].clear();
            d.p[x]=x,d.p[y]=y;
            used[x]=0,used[y]=0;
        }
    }
    for(int i=0;i<comp.size();i++)
    {
        for(int j=0;j<comp[i].size();j++)
        {
            appear[comp[i][j]].PB(i);
        }
    }
    for(int i=1;i<=n;i++)if(appear[i].size()>=bucket)bigid[i]=big.size(),big.PB(i);else bigid[i]=-1;
    for(int i=0;i<big.size();i++)
    {
        for(int j=0;j<appear[big[i]].size();j++)
        {
            int id=appear[big[i]][j];
            for(int k=0;k<comp[id].size();k++)query[i][comp[id][k]]++;
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        if(bigid[y]==-1)swap(x,y);
        if(bigid[y]!=-1)cout<<query[bigid[y]][x]<<endl;
        else
        {
            int p1=0,p2=0,res=0;
            while(p1<appear[x].size()&&p2<appear[y].size())
            {
                if(appear[x][p1]==appear[y][p2])p1++,p2++,res++;
                else if(appear[x][p1]<appear[y][p2])p1++;
                else p2++;
            }
            cout<<res<<endl;
        }
    }
    return 0;
}