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
vector<pair<int,pl> >ov;
void make(ll x,ll mul)
{
    if(mul==1)
        return;
    if(mul%2==0)
    {
        make(x,mul/2);
        ov.eb(1,pl(x*mul/2,x*mul/2));
    }
    else
    {
        make(x,(mul-1)/2);
        ov.eb(1,pl(x*(mul-1)/2,x*(mul-1)/2));
        ov.eb(1,pl(x*(mul-1),x));
    }
    return;
}
inline ll reduce(ll x)
{
    int p=0;
    while(x>(1ll<<p))
        p++;
    ll m1=1ll<<p;
    ll m2=m1-1;
    make(x,m1);
    make(x,m2);
    ov.eb(2,pl(x*m1,x*m2));
    ov.eb(1,pl(m1+m1-x,x));
    ll y=x;
    while(y!=m1)
    {
        ov.eb(1,pl(y,y));
        y*=2;
        if(y>=m1+m1)
        {
            ov.eb(2,pl(y,m1+m1));
            y-=m1+m1;
        }
    }
    ov.eb(2,pl(m1+m1-x,m1));
    return m1-x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x;
    cin>>x;
    while(x!=1)
        x=reduce(x);
    cout<<ov.size()<<endl;
    for(auto&t:ov)
    {
        if(t.fi==1)
            cout<<t.se.fi<<" + "<<t.se.se<<'\n';
        else
            cout<<t.se.fi<<" ^ "<<t.se.se<<'\n';
    }
    return 0;
}