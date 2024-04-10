#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 1000004

using namespace std;
typedef long long ll;

ll p[maxn],q[maxn],a[maxn],b[maxn],n,x,y,r;
char s[maxn],t[maxn];

ll pow_(ll x,ll y)
{
    if (y==0) return 1;
    ll tt=pow_(x,y/2);tt=tt*tt%mod;
    if (y&1) tt=tt*x%mod;
    return tt;
}

int main()
{
    p[0]=1; q[0]=1; x=0;y=0;
    for (int i=1;i<maxn;i++) p[i]=p[i-1]*i%mod;
    for (int i=1;i<maxn;i++) q[i]=pow_(i,mod-2);
    scanf("%s",s);scanf("%s",t);n=strlen(s);
    for (int i=0;i<26;i++) a[i]=b[i]=0;
    for (int i=0;i<n;i++) a[s[i]-'a']++,b[s[i]-'a']++;
    r=p[n]; for (int i=0;i<26;i++) for (int j=1;j<=a[i];j++) r=r*q[j]%mod;
    for (int i=0;i<n;i++)
    {
        int k=s[i]-'a';
        for (int j=0;j<k;j++) x=(x+(r*q[n-i]%mod)*a[j]%mod)%mod;
        if (!a[k]) break;
        r=(r*q[n-i])%mod*a[k]%mod;a[k]--;
    }
    r=p[n]; for (int i=0;i<26;i++) for (int j=1;j<=b[i];j++) r=r*q[j]%mod;
    for (int i=0;i<n;i++)
    {
        int k=t[i]-'a';
        for (int j=0;j<k;j++) y=(y+(r*q[n-i]%mod)*b[j]%mod)%mod;
        if (!b[k]) break;
        r=(r*q[n-i])%mod*b[k]%mod;b[k]--;
    }
    printf("%d\n",(y-x-1+mod)%mod);
    return 0;
}