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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin>>n;
    vector<vector<ll> >v(n);
    vector<pl>q;
    for(auto&t:v)
    {
        ll x;
        cin>>x;
        t.resize(x);
        ll m=INF,M=-INF;
        ll f=0;
        for(auto&s:t)
        {
            cin>>s;
            if(s>m)
                f=1;
            M=max(M,s);
            m=min(m,s);
        }
        if(f==0)
            q.eb(m,1),q.eb(M,0);
    }
    sort(all(q));
    ll ans=(ll)n*n;
    ll c=0;
    for(pl&t:q)
    {
        if(t.se==1)
            ans-=c;
        else
            c++;
    }
    cout<<ans<<endl;
    return 0;
}