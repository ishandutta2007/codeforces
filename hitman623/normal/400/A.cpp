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
    long t,f,i,j,k;
    cin>>t;
    while(t--)
    {
        vl v;
        cin>>s;
        for(i=1;i<=12;++i)
        if(12%i==0)
        {
            for(k=0;k<12/i;++k)
            {
                f=1;
                for(j=k;j<12;j+=12/i)
                if(s[j]!='X') f=0;
                if(f) {v.pb(i);break;}
            }
        }
        cout<<v.size()<<" ";
        for(i=0;i<v.size();++i)
        cout<<v[i]<<"x"<<12/v[i]<<" ";
        cout<<endl;
    }
    return 0;
}