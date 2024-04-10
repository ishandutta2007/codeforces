#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;
typedef long long ll;

ll n,m,k,r,ans,c[8],d[4],e[4],f[4],g[4],inv2,inv3,inv5,inv6,inv7,inv30,inv42,z,np;

int main()
{
    scanf("%I64d",&n); np=n%mod; k=1000000;
    ans=0; d[0]=1; c[0]=1;
    inv2=500000004; inv3=333333336; inv5=400000003; inv6=inv2*inv3%mod;
    inv7=142857144; inv30=inv5*inv6%mod; inv42=inv6*inv7%mod;
    for (int i=1;i<4;i++) d[i]=d[i-1]*np%mod;
    for (ll i=0;i*i<=n;i++)
    {
        m=n-i*i; r=0; z=i*i%mod;
        while (k*k>m) k--;
        for (int i=1;i<8;i++) c[i]=c[i-1]*k%mod;
        e[0]=(2ll*k+1)%mod;
        e[1]=(k*inv6+c[2]*inv2+c[3]*inv3)%mod;
        e[2]=(-k*inv30+c[3]*inv3+c[4]*inv2+c[5]*inv5)%mod+mod;
        e[3]=(k*inv42-c[3]*inv6+c[5]*inv2+c[6]*inv2+c[7]*inv7)%mod+mod;
        for (int i=1;i<4;i++) e[i]=e[i]*2%mod;
        f[0]=(d[3]*inv6%mod+d[2]*inv2%mod+d[1]*inv3%mod)%mod;
        f[1]=(np*inv2+2ll*inv3)%mod; f[2]=((mod-np*inv2-1)%mod+mod)%mod; f[3]=inv3;
        g[0]=(f[0]+f[1]*z%mod+f[2]*z%mod*z%mod+f[3]*z%mod*z%mod*z%mod)%mod;
        g[1]=(f[1]+f[2]*z*2%mod+f[3]*z%mod*z*3%mod)%mod;
        g[2]=(f[2]+f[3]*z*3)%mod; g[3]=f[3];
        for (int i=0;i<4;i++) r=(r+e[i]*g[i])%mod;
        if (i) ans=(ans+r*2)%mod; else ans=(ans+r)%mod;
    }
    cout << ans << endl;
    return 0;
}