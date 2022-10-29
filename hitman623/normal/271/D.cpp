#include <bits/stdc++.h>
#define pb push_back
#define long unsigned long long
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
    unordered_map < long , long > mp;
    long k,n,h,p=101221,hell=114893512457,i,j,cnt;
    string s1,s2;
    cin>>s1>>s2>>k;
    n=s1.length();
    for(i=0;i<n;++i)
    {
        h=0;
        cnt=0;
        for(j=i;j<n;++j)
        {
            h=(h*131)^s1[j];
            cnt+=!(s2[s1[j]-'a']-'0');
            if(cnt<=k)
            mp[h]=1;
            else break;
        }
    }
    cout<<mp.size();
    return 0;
}