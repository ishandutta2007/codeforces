#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,ans;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        ans=n;
        for(int i=1;i<n+n;++i)
            if(s[i-1]==')'&&s[i]=='(')
                --ans;
        cout<<ans<<'\n';
    }
    return 0;
}