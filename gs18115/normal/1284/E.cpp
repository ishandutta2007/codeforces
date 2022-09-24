#include<iostream>
#include<vector>
#include<queue>
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
pl operator-(pl x,pl y)
{
    return pl(x.fi-y.fi,x.se-y.se);
}
inline int sg(ll p)
{
    return p>0?1:-1;
}
inline int ccw(pl x,pl y)
{
    return sg(x.fi*y.se-x.se*y.fi);
}
inline int ccw(pl x,pl o,pl y)
{
    x=x-o;
    y=y-o;
    return sg(x.fi*y.se-x.se*y.fi);
}
inline bool ccw2(pl x,pl y)
{
    int a=x.se==0?x.fi<0:x.se<0;
    int b=y.se==0?y.fi<0:y.se<0;
    if(a!=b)
        return a<b;
    return x.fi*y.se-x.se*y.fi>0;
}
vector<pl>p;
inline bool c(int x,int y,int z,int l)
{
    return ccw(p[y],p[x],p[z])==ccw(p[z],p[x],p[l]);
}
inline ll nc3(ll x)
{
    return x*(x-1)*(x-2)/6;
}
inline ll nc4(ll x)
{
    return x*(x-1)*(x-2)*(x-3)/24;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    p.resize(n);
    for(auto&t:p)
        cin>>t.fi>>t.se;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        vector<pl>cop=p;
        swap(p[0],p[i]);
        n--;
        for(int j=0;j++<n;)
            p[j]=p[j]-p[0];
        sort(1+all(p),ccw2);
        queue<pl>qq;
        ans+=nc4(n);
        for(int j=1;j++<n;)
            if(ccw(p[j],p[1])==1)
                qq.push(p[j]);
        for(int j=0;j++<n;)
        {
            while(!qq.empty())
            {
                if(p[j]==qq.front()||ccw(p[j],qq.front())==1)
                    qq.pop();
                else
                    break;
            }
            ans-=nc3(qq.size());
            qq.push(p[j]);
        }
        p=cop;
        n++;
    }
    cout<<ans<<endl;
    return 0;
}