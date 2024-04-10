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
        ans=0;
        cin>>s;
        n=s.length();
        for(register int i=1;i<n;++i)
            ans+=(s[i-1]^48^1)&&(s[i]^s[i-1]);
        cout<<min(2,ans+(s[n-1]^48^1))<<endl;
    }
    return 0;
}