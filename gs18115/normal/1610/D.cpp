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
const int mod=1e9+7;
inline int add(int x,int y)
{
    return x+y<mod?x+y:x+y-mod;
}
inline int mul(int x,int y)
{
    return (ll)x*y%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int>v(n);
    for(int&t:v)
        cin>>t;
    vector<int>o,e;
    for(int&t:v)
        (t%2==1?o:e).eb(t);
    vector<int>cv(35,0);
    for(int&t:e)
        cv[__builtin_ctz(t)]++;
    int oc=1,ec=1;
    for(int i=0;i<(int)o.size();i++)
        oc=mul(oc,2);
    for(int i=0;i<(int)e.size();i++)
        ec=mul(ec,2);
    oc=add(oc,mod-1);
    oc=mul(oc,ec);
    reverse(all(cv));
    int cc=0,cc2=1;
    for(int&t:cv)
    {
        if(t>1)
        {
            int ccc=1;
            for(int i=1;i<t;i++)
                ccc=mul(ccc,2);
            oc=add(oc,mul(ccc-1,cc2));
        }
        for(int i=0;i<t;i++)
            cc++,cc2=mul(cc2,2);
    }
    cout<<oc<<endl;
    return 0;
}