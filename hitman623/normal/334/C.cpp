#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
    io
    long n,t=3,ans=1;
    cin>>n;
    while(t<=n)
    {
        if(n%t==0) {t=t*3;continue;}
        ans=max(ans,n/t+1);
        t=t*3;
    }
    cout<<ans;
    return 0;
}