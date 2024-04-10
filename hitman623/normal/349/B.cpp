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

int main()
{
    io
    long n,a[10],i,ans=1e9,d=0,c,f[10]={0};
    cin>>n;
    for(i=1;i<10;++i)
    {
        cin>>a[i];
        if(a[i]<=ans)
        {
            ans=a[i];
            d=i;
        }
    }
    c=n/ans;
    f[d]=c;
    if(c==0) {cout<<-1;exit(0);}
    n%=ans;
    for(i=9;i>0;i--)
    if(i>d && a[i]>a[d])
    {
        f[i]+=n/(a[i]-a[d]);
        f[d]-=n/(a[i]-a[d]);
        n%=(a[i]-a[d]);
    }
    for(i=9;i>0;i--)
    while(f[i])
    {
        cout<<i;
        f[i]--;
    }
    return 0;
}