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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin>>tc;
    for(int tci=0;tci<tc;tci++)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int&t:v)
            cin>>t;
        int mx=0;
        for(int&t:v)
            mx=max(mx,t);
        int mc=0,m2c=0;
        for(int&t:v)
        {
            if(t==mx)
                mc++;
            else if(t==mx-1)
                m2c++;
        }
        int ans=1;
        for(int i=0;i++<n;)
            ans=mul(ans,i);
        if(mc>1)
            cout<<ans<<'\n';
        else
        {
            int sb=1;
            for(int i=0;i++<n;)
                if(i!=mc+m2c)
                    sb=mul(sb,i);
            cout<<sub(ans,sb)<<'\n';
        }
    }
    return 0;
}