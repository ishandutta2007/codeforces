#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
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
const int inf=1e9+7;
const ll INF=1e18;
ll c[300010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int V,e,i;
    cin>>V>>e;
    for(i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        c[u]+=w;
        c[v]-=w;
    }
    vector<pair<pi,ll> >v;
    vector<pl>ps,ms;
    for(i=0;i++<V;)
    {
        if(c[i]<0)
        {
            while(!ps.empty())
            {
                if(ps.back().se+c[i]<=0)
                    v.eb(pl(ps.back().fi,i),ps.back().se),c[i]+=ps.back().se,ps.pop_back();
                else
                    break;
            }
            if(c[i]<0)
            {
                if(ps.empty())
                    ms.eb(i,c[i]);
                else
                    v.eb(pi(ps.back().fi,i),-c[i]),ps.back().se+=c[i];
            }
        }
        else
        {
            while(!ms.empty())
            {
                if(ms.back().se+c[i]>=0)
                    v.eb(pl(i,ms.back().fi),-ms.back().se),c[i]+=ms.back().se,ms.pop_back();
                else
                    break;
            }
            if(c[i]>0)
            {
                if(ms.empty())
                    ps.eb(i,c[i]);
                else
                    v.eb(pi(i,ms.back().fi),c[i]),ms.back().se+=c[i];
            }
        }
    }
    cout<<v.size();
    for(auto t:v)
        cout<<'\n'<<t.fi.fi<<' '<<t.fi.se<<' '<<t.se;
    cout<<endl;
    return 0;
}