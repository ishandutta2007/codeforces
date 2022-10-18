#include <cstdio>

#define ll long long

using namespace std;

int main()
{
    ll dob=1;
    int Lev=5,ans=0,mod=1e+9+9,n=0;
    scanf("%d",&n);
    n/=2;
    if (n==1) ans=10;
    else
    {
        for(int i=3;i<=n;++i)
        {
            dob=(dob*Lev)%mod;
            ans=(4*dob+ans)%mod;
            Lev=(2*Lev+3)%mod;
        }
        ans=(2*(((ll)ans+6)*(ans+6)+mod-4)+10)%mod;
    }
    printf("%d\n",ans);
    return 0;
}