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
    string s;
    char cur;
    long n,i,c=1,p[100005]={0},d[100005]={0};
    cin>>n>>s;
    cur=s[0];
    for(i=n-2;i>=0;i--)
    p[i]=max(p[i+1],(long)(s[i]=='1' && s[i+1]=='1'));
    for(i=n-2;i>=0;i--)
    d[i]=max(d[i+1],(long)(s[i]=='0' && s[i+1]=='0'));
    for(i=0;i<n;++i)
    if(s[i]!=cur)
    c++,cur=s[i];
    for(i=0;i<n-2;++i)
    if(s[i]=='0' && s[i+1]=='0' && s[i+2]=='0')
    {cout<<c+2;return 0;}
    else if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='1')
    {cout<<c+2;return 0;}
    for(i=0;i<n-2;++i)
    if(s[i]=='0' && s[i+1]=='0' && (p[i+2] || d[i+2])) {cout<<c+2;return 0;}
    else if(s[i]=='1' && s[i+1]=='1' && (d[i+2] || p[i+2])) {cout<<c+2;return 0;}
    for(i=0;i<n-1;++i)
    if(s[i]=='0' && s[i+1]=='0') {cout<<c+1;return 0;}
    for(i=0;i<n-1;++i)
    if(s[i]=='1' && s[i+1]=='1') {cout<<c+1;return 0;}
    cout<<c;
    return 0;
}