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
const ll INF=1e18+7;
const ll mod1=993244853;
const ll mod2=1e9+9;
const ll mul=1753891;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
    {
        int n,m;
        cin>>n>>m;
        vector<int>lst;
        vector<ll>val(n);
        for(ll&t:val)
            cin>>t;
        vector<vector<int> >adj(n);
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[v-1].eb(u-1);
        }
        ll g=0;
        vector<pair<int,pl> >h(n);
        vector<pair<int,pl> >cp;
        for(int i=0;i<n;i++)
        {
            if(adj[i].empty())
                continue;
            sort(all(adj[i]));
            ll h1=0,h2=0;
            for(int&t:adj[i])
                h1=(h1*mul+t)%mod1,h2=(h2*mul+t)%mod2;
            h[i]=pair<int,pl>((int)adj[i].size(),pl(h1,h2));
            cp.eb(h[i]);
        }
        sort(all(cp));
        cp.erase(unique(all(cp)),cp.end());
        vector<vector<int> >vv(cp.size());
        for(int i=0;i<n;i++)
            if((int)adj[i].size()>0)
                vv[lower_bound(all(cp),h[i])-cp.begin()].eb(i);
        for(auto&v2:vv)
        {
            ll s=0;
            for(auto&t:v2)
                s+=val[t];
            g=__gcd(s,g);
        }
        cout<<g<<'\n';
    }
    cout.flush();
    return 0;
}