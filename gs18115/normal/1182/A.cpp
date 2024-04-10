#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
const LL mod=1e18+7;
inline LL Pow(LL x,LL y)
{
    LL ret=1;
    while(y>0)
    {
        if(y&1)
            ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}
LL N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
if(N&1)
cout<<0<<endl;
else
cout<<Pow(2,N>>1)<<endl;
    return 0;
}