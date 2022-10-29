#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pair < long , long > pll
using namespace std;

int main()
{
    string s,b;
    cin>>s;
    if(s=="CODEFORCES") {cout<<"YES";exit(0);}
    long n=s.length(),i,j,k;
    for(i=0;i<n;++i)
    for(j=0;j<n;++j)
    {
        b.clear();
        for(k=0;k<i;++k)
        b.pb(s[k]);
        for(k=j+1;k<n;++k)
        b.pb(s[k]);
        if(b=="CODEFORCES") {cout<<"YES";exit(0);}
    }
    cout<<"NO";
    return 0;
}