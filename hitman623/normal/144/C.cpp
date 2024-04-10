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

    string s,p;
    cin>>s>>p;
    long c[26]={0},cur[26]={0},ans=0,j,i,m,ex=0;
    for(i=0;i<p.length();++i)
    c[p[i]-'a']++;
    for(i=0;i<s.length();++i)
    {
        if(s[i]!='?')
        cur[s[i]-'a']++;
        else ex++;
        m=ex;
        for(j=0;j<26;++j)
        m-=max((long)0,(c[j]-cur[j]));
        if(m>=0)
        ans++;
        if(i>=p.length()-1)
        {
            if(s[i-p.length()+1]!='?')
            cur[s[i-p.length()+1]-'a']--;
            else ex--;
        }
    }
    cout<<ans;
    return 0;
}