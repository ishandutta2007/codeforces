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
int mp[2010][2010];
inline void flip(pi x)
{
    mp[x.fi][x.se]^=1;
    return;
}
inline void flip(pair<pair<pi,pi>,pi>x)
{
    flip(x.fi.fi);
    flip(x.fi.se);
    flip(x.se);
    return;
}
inline void print(pi x)
{
    cout<<x.fi+1<<' '<<x.se+1<<' ';
}
inline void print2(pi x)
{
    cout<<x.fi+1<<' '<<x.se+1<<'\n';
}
inline void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            mp[i][j]=c-'0';
        }
    vector<pair<pair<pi,pi>,pi> >vx;
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<m;j++)
        {
            int ni=i+1;
            int nj=max(j-1,0);
            if(mp[i][j]==1)
                vx.eb(pair<pi,pi>(pi(i,j),pi(ni,nj)),pi(ni,nj+1)),
                flip(vx.back());
        }
    }
        for(int j=0;j<m-2;j++)
    {
    for(int i=n-2;i<n;i++)
        {
            int ni=n-2;
            int nj=j+1;
            if(mp[i][j]==1)
                vx.eb(pair<pi,pi>(pi(i,j),pi(ni,nj)),pi(ni+1,nj)),
                flip(vx.back());
        }
    }
    vector<pi>ov,zv;
    for(int i=n-2;i<n;i++)
        for(int j=m-2;j<m;j++)
            (mp[i][j]==1?ov:zv).eb(i,j);
    if((int)ov.size()==1)
    {
        vx.eb(pair<pi,pi>(zv[0],zv[1]),ov[0]);
        vx.eb(pair<pi,pi>(zv[0],zv[2]),ov[0]);
        vx.eb(pair<pi,pi>(zv[1],zv[2]),ov[0]);
    }
    else if((int)ov.size()==2)
    {
        vx.eb(pair<pi,pi>(zv[0],zv[1]),ov[0]);
        vx.eb(pair<pi,pi>(zv[0],zv[1]),ov[1]);
    }
    else if((int)ov.size()==3)
    {
        vx.eb(pair<pi,pi>(ov[0],ov[1]),ov[2]);
    }
    else if((int)ov.size()==4)
    {
        vx.eb(pair<pi,pi>(ov[0],ov[1]),ov[2]);
        vx.eb(pair<pi,pi>(ov[0],ov[1]),ov[3]);
        vx.eb(pair<pi,pi>(ov[0],ov[2]),ov[3]);
        vx.eb(pair<pi,pi>(ov[1],ov[2]),ov[3]);
    }
    cout<<vx.size()<<'\n';
    for(auto&t:vx)
        print(t.fi.fi),print(t.fi.se),print2(t.se);
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
        solve();
    return 0;
}