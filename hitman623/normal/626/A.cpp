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
string s;
long n,i,j,c=0;
long check(long x,long y)
{
    long i,u=0,r=0;
    for(i=x;i<=y;++i)
    if(s[i]=='U') u++;
    else if(s[i]=='D') u--;
    else if(s[i]=='R') r++;
    else r--;
    return (r==0 && u==0);
}
int main()
{
    io
    cin>>n;
    cin>>s;
    for(i=0;i<n;++i)
    for(j=i+1;j<n;++j)
    if(check(i,j)) c++;
    cout<<c;
    return 0;
}