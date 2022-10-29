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
long cal(long x,long m,long w)
{
    return max((3*x)/10,((250-m)*x)/250-50*w);
}
int main()
{
    io
    long m[5],w[5],i,hs,hu,ans=0;
    for(i=0;i<5;++i)
    cin>>m[i];
    for(i=0;i<5;++i)
    cin>>w[i];
    cin>>hs>>hu;
    for(i=0;i<5;++i)
    ans+=cal(500+i*500,m[i],w[i]);
    cout<<ans+100*hs-50*hu;
    return 0;
}