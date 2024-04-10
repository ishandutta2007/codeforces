#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
        if(s.length()==2)
            cout<<s[1]<<'\n';
        else
        {
            int ans=10;
            for(auto i:s)
                ans=min(ans,i-'0');
            cout<<ans<<'\n';
        }
    }
    return 0;
}