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
struct dsu
{
    vector<int>p,d;
    dsu(){}
    dsu(int n)
    {
        p.resize(n+1,0);
        d.resize(n+1,0);
    }
    pi par(int x)
    {
        if(p[x]==0)
            return pi(x,0);
        pi t=par(p[x]);
        return pi(p[x]=t.fi,d[x]=t.se^d[x]);
    }
    bool uni(int xx,int yy,int dd)
    {
        pi x=par(xx);
        pi y=par(yy);
        if(x.fi==y.fi)
            return (x.se^y.se^dd)!=0;
        p[x.fi]=y.fi;
        d[x.fi]=dd^x.se^y.se;
        return 0;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,m;
        cin>>n>>m;
        dsu uf(n);
        bool f=0;
        vector<pair<pi,int> >eg;
        for(int i=1;i<n;i++)
        {
            int u,v,d;
            cin>>u>>v>>d;
            eg.eb(pi(u,v),d);
            if(d!=-1)
            {
                d=__builtin_popcount(d)%2;
                if(uf.uni(u,v,d))
                    f=1;
            }
        }
        for(int i=0;i<m;i++)
        {
            int u,v,d;
            cin>>u>>v>>d;
            if(uf.uni(u,v,d))
                f=1;
        }
        cout<<(f?"NO":"YES")<<'\n';
        if(f)
            continue;
        for(auto&t:eg)
        {
            cout<<t.fi.fi<<' '<<t.fi.se<<' ';
            if(t.se==-1)
                cout<<(uf.par(t.fi.fi).se^uf.par(t.fi.se).se)<<'\n';
            else
                cout<<t.se<<'\n';
        }
    }
    return 0;
}