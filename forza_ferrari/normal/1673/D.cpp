#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int mod=1000000007;
int t,a[4],b[4],ans;
inline int gcd(int x,int y)
{
    return x%y? gcd(y,x%y):y;
}
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>a[0]>>a[1]>>a[2]>>b[0]>>b[1]>>b[2];
        ans=0;
        a[3]=a[0]+a[1]*(a[2]-1);
        b[3]=b[0]+b[1]*(b[2]-1);
        if((b[0]-a[0])%a[1]||b[1]%a[1]||b[0]<a[0]||a[3]<b[3])
        {
            cout<<"0\n";
            continue;
        }
        if(b[0]-b[1]<a[0]||b[3]+b[1]>a[3])
        {
            cout<<"-1\n";
            continue;
        }
        for(int i=1;i*i<=b[1];++i)
            if(b[1]%i==0)
            {
                if(gcd(i,b[1]/a[1])==1)
                    ans=(ans+i*i%mod)%mod;
                if(i*i!=b[1])
                    if(gcd(b[1]/i,b[1]/a[1])==1)
                        ans=(ans+b[1]*b[1]/i/i%mod)%mod;
            }
        cout<<ans<<'\n';
    }
    return 0;
}