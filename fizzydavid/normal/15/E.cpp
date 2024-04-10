//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const ll mod=1e9+9;
ll ans,n,pow2,tmp;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    pow2=8;tmp=1;
    for(int p=2,i;p<=n;p++)
    {
        if((p&1)&&p>4)
        {
            if(p<n)tmp=(tmp*(pow2-3)+3*mod)%mod,pow2=pow2*2%mod;else tmp=tmp*(p-2)%mod;
        }
        ans=(ans+2*tmp)%mod;
    }
    ans=(ans*ans+1)*2%mod;
    cout<<ans<<endl;
    return 0;
}