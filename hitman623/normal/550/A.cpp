#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    string s;
    long i,n,ab=0,ba=0,l,r;
    cin>>s;
    n=s.length();
    for(i=0;i<n-1;++i)
    if(s[i]=='A' && s[i+1]=='B') break;
    if(i==n-1) {cout<<"NO";exit(0);}
    i+=2;
    for(;i<n-1;++i)
    if(s[i]=='B' && s[i+1]=='A') break;
    if(i<n-1) {cout<<"YES";exit(0);}
    for(i=0;i<n-1;++i)
    if(s[i]=='B' && s[i+1]=='A') break;
    if(i==n-1) {cout<<"NO";exit(0);}
    i+=2;
    for(;i<n-1;++i)
    if(s[i]=='A' && s[i+1]=='B') break;
    if(i<n-1) {cout<<"YES";exit(0);}
    cout<<"NO";
    return 0;
}