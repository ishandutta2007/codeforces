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
long n,l,r,ql,qr,i,w[100005],j=0,k=n-1,p[100005]={0},s[100005]={0},ans=1e15,ll,rr;
int main()
{
    io
    cin>>n>>l>>r>>ql>>qr;
    for(i=1;i<=n;++i)
    cin>>w[i];
    p[1]=w[1];
    for(i=2;i<=n;++i)
    p[i]=w[i]+p[i-1];
    s[n]=w[n];
    for(i=n-1;i>0;--i)
    s[i]=w[i]+s[i+1];
    for(i=0;i<=n;++i)
    {
        ll=i;
        rr=n-ll;
        ans=min(ans,p[ll]*l+s[ll+1]*r+ql*max(0LL,ll-rr-1)+qr*max(0LL,rr-ll-1));
    }
    cout<<ans;
    return 0;
}