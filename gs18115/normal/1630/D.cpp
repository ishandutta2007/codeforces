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
inline int gcd2(int x,int y)
{
    while(y>0)
    {
        int t=x%y;
        x=y;
        y=t;
    }
    return x;
}
inline ll solve(vector<int>v)
{
    int n=v.size();
    vector<ll>dp1(n,-INF),dp2(n,-INF);
    dp1[0]=0;
    for(int i=1;i<n;i++)
    {
        dp1[i]=max(dp1[i-1]+v[i-1],dp2[i-1]-v[i-1]);
        dp2[i]=max(dp1[i-1]-v[i-1],dp2[i-1]+v[i-1]);
    }
    return max(dp1[n-1]+v[n-1],dp2[n-1]-v[n-1]);
}
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
        vector<int>v(n);
        for(int&t:v)
            cin>>t;
        int g=0;
        for(int i=0;i<m;i++)
        {
            int x;
            cin>>x;
            g=gcd2(g,x);
        }
        if(g==1)
        {
            ll s=0;
            for(int&t:v)
                s+=abs(t);
            cout<<s<<'\n';
            continue;
        }
        ll ans=-INF;
        //case 1: even number
        {
            vector<vector<int> >vv(g);
            for(int i=0;i<n;i++)
                vv[i%g].eb(v[i]);
            ll s=0;
            for(auto&t:vv)
                s+=solve(t);
            ans=max(ans,s);
        }
        //case 2: odd number
        {
            for(int i=0;i<g;i++)
                v[i]=-v[i];
            vector<vector<int> >vv(g);
            for(int i=0;i<n;i++)
                vv[i%g].eb(v[i]);
            ll s=0;
            for(auto&t:vv)
                s+=solve(t);
            ans=max(ans,s);
        }
        cout<<ans<<'\n';
    }
    return 0;
}