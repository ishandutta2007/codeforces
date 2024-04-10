#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf=1e18;
vector<int>hg[100010];
ll alls;
ll ls[100010];
ll low[100010];
int n,m,q,i;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        int s,e;
        cin>>s>>e;
        if(s>e)
            swap(s,e);
        hg[s].eb(e);
        low[e]++;
    }
    for(i=0;i++<n;)
        for(int t:hg[i])
            ls[t]+=low[i];
    for(i=0;i++<n;)
        alls+=ls[i];
    cout<<alls;
    cin>>q;
    for(i=0;i<q;i++)
    {
        int v;
        cin>>v;
        for(int t:hg[v])
        {
            ls[t]-=low[v];
            ls[v]+=--low[t];
            alls+=low[t]-low[v]-hg[t].size();
            hg[t].eb(v);
        }
        low[v]+=hg[v].size();
        hg[v].clear();
        cout<<'\n'<<alls;
    }
    cout<<endl;
    return 0;
}