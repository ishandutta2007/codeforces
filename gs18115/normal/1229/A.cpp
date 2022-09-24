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
bool c[7010],chk[7010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,i;
    cin>>n;
    vector<ll>V;
    vector<pl>v(n);
    for(i=0;i<n;i++)
        cin>>v[i].fi,V.eb(v[i].fi);
    for(i=0;i<n;i++)
        cin>>v[i].se;
    sort(all(V));
    V.erase(unique(all(V)),V.end());
    ll mx=0;
    for(i=0;i<V.size();i++)
    {
        ll j;
        ll cnt=0;
        ll ans=0;
        for(j=0;j<v.size();j++)
        {
            if(V[i]==v[j].fi)
                cnt++;
            if((V[i]&v[j].fi)==v[j].fi)
                chk[j]=true;
            else
                chk[j]=false;
        }
        if(cnt>1)
            for(j=0;j<v.size();j++)
                if(chk[j])
                    c[j]=true;
    }
    for(i=0;i<v.size();i++)
        if(c[i])
            mx+=v[i].se;
    cout<<mx<<endl;
    return 0;
}