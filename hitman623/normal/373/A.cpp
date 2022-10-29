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
    long k,i,j,v[10]={0};
    cin>>k;
    for(i=0;i<4;++i)
    {
        cin>>s;
        for(j=0;j<4;++j)
        if(isdigit(s[j]))
        v[s[j]-'0']++;
    }
    for(i=0;i<10;++i)
    if(v[i]>2*k) {cout<<"NO";exit(0);}
    cout<<"YES";
    return 0;
}