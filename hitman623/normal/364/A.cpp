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
    map < long , long > f;
    map < long , long > ::iterator it;
    long a,i,j,b[4004],ans=0,n,ss;
    cin>>a>>s;
    n=s.length();
    for(i=0;i<n;++i)
    b[i]=s[i]-'0';
    for(i=0;i<n;++i)
    {
        ss=0;
        for(j=i;j<n;++j)
        {
            ss+=b[j];
            f[ss]++;
        }
    }
    if(a==0)
    {
        ss=0;
        for(it=f.begin();it!=f.end();it++)
        ss+=it->y;
        cout<<2*f[0]*(ss-f[0])+(f[0]*f[0]);
        return 0;
    }
    for(it=f.begin();it!=f.end();it++)
    if(it->first && a%(it->first)==0 && f.find(a/it->first)!=f.end())
    ans+=(it->second)*f[a/(it->first)];
    cout<<ans;
    return 0;
}