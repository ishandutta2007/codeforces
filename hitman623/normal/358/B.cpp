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
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    io
    string s,w[100005],t,h="<3";
    t=h;
    long n,i,j=0;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>w[i];
        t.append(w[i]);
        t.append(h);
    }
    cin>>s;
    for(i=0;i<s.length();++i)
    {
        if(s[i]==t[j]) j++;
        if(j==t.length()) break;
    }
    if(j==t.length()) cout<<"yes";
    else cout<<"no";
    return 0;
}