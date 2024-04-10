#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,ans;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
        ans=0;
        for(auto i:s)
            ans=max(ans,i-'0');
        cout<<ans<<'\n';
    }
    return 0;
}