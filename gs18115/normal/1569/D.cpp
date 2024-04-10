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
const int mod=998244353;
inline int add(int x,int y)
{
    return x+y<mod?x+y:x+y-mod;
}
inline int sub(int x,int y)
{
    return add(x,y==0?0:mod-y);
}
inline int mul(int x,int y)
{
    return(int)((ll)x*y%mod);
}
bool cx[1000010],cy[1000010];
vector<int>vx[1000010],vy[1000010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin>>tc;
    for(int tci=0;tci<tc;tci++)
    {
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>xv(n),yv(m);
        vector<pi>pv(k);
        for(int&t:xv)
            cin>>t,cx[t]=1;
        for(int&t:yv)
            cin>>t,cy[t]=1;
        vector<int>x2v=xv,y2v=yv;
        for(pi&t:pv)
        {
            cin>>t.fi>>t.se;
            if(!cx[t.fi])
                vx[t.fi].eb(t.se);
            if(!cy[t.se])
                vy[t.se].eb(t.fi);
            x2v.eb(t.fi),y2v.eb(t.se);
        }
        sort(all(x2v));
        x2v.erase(unique(all(x2v)),x2v.end());
        sort(all(y2v));
        y2v.erase(unique(all(y2v)),y2v.end());
        ll ans=0;
        vector<int>swp;
        for(int&t:x2v)
        {
            if(cx[t])
            {
                sort(all(swp));
                int nn=swp.size();
                ans+=(ll)nn*nn;
                for(int i=0;i<nn;)
                {
                    int j=i+1;
                    while(j<nn&&swp[j]==swp[i])
                        j++;
                    int mm=j-i;
                    ans-=(ll)mm*mm;
                    i=j;
                }
                swp.clear();
            }
            for(int&t:vx[t])
                swp.eb(t);
        }
        for(int&t:y2v)
        {
            if(cy[t])
            {
                sort(all(swp));
                int nn=swp.size();
                ans+=(ll)nn*nn;
                for(int i=0;i<nn;)
                {
                    int j=i+1;
                    while(j<nn&&swp[j]==swp[i])
                        j++;
                    int mm=j-i;
                    ans-=(ll)mm*mm;
                    i=j;
                }
                swp.clear();
            }
            for(int&t:vy[t])
                swp.eb(t);
        }
        for(int&t:x2v)
            cx[t]=0,vx[t].clear();
        for(int&t:y2v)
            cy[t]=0,vy[t].clear();
        ans/=2;
        cout<<ans<<'\n';
    }
    return 0;
}