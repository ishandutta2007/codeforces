#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long h=1e9+7;
long po(long a,long b)
{
    if(a==0) return 0;
    if(a==1 || b==0) return 1;
    long m=po(a,b/2);
    if(b&1) return (((m*m)%h)*a)%h;
    return (m*m)%h;
}
int main()
{
    io
    long n,a[200005]={0},x,i,hh=h-1,f=0,p=1,ans=1;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>x;
        a[x]++;
    }
    for(i=2;i<200005;++i)
    {
        if(f==0 && a[i]&1)
        p=(p*((a[i]+1)/2))%hh,f=1;
        else p=(p*(a[i]+1))%hh;
    }
    for(i=2;i<200005;++i)
    {
        if(f==0) a[i]/=2;
        ans=(ans*po(i,(a[i]*p)%hh))%h;
    }
    cout<<ans;
    return 0;
}