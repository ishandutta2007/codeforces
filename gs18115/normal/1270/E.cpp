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
ll x[100010],y[100010],z[100010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,i;
    ll g=0;
    cin>>n;
    cin>>x[0]>>y[0];
    for(i=1;i<n;i++)
        cin>>x[i]>>y[i],x[i]-=x[0],y[i]-=y[0];
    x[0]=y[0]=0;
    for(i=1;i<n;i++)
        g=__gcd(__gcd(g,x[i]),y[i]);
    for(i=1;i<n;i++)
        x[i]/=g,y[i]/=g;
    vector<int>v;
    for(i=1;i<n;i++)
        if(x[i]+y[i]&1)
            v.eb(i+1);
    if(v.empty())
    {
        for(i=1;i<n;i++)
            x[i]+=y[i],y[i]=x[i]-2*y[i];
        g=0;
        for(i=1;i<n;i++)
            g=__gcd(__gcd(g,x[i]),y[i]);
        for(i=1;i<n;i++)
            x[i]/=g,y[i]/=g;
        for(i=1;i<n;i++)
            if(x[i]+y[i]&1)
                v.eb(i+1);
    }
    cout<<v.size()<<endl;
    for(int&t:v)
        cout<<t<<' ';
    cout<<endl;
    return 0;
}