#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
#define int long long
int t,x,n;
const int mod=1000000007;
string s;
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&x);
        cin>>s;
        n=s.length();
        for(register int i=0;i<x;++i)
            if(s.length()>=x)
                n=(n+(n-i-1+mod)%mod*(s[i]-'1'))%mod;
            else
            {
                if(s[i]=='2')
                    s+=s.substr(i+1);
                if(s[i]=='3')
                    s+=s.substr(i+1)+s.substr(i+1);
                n=s.length();
            }
        printf("%lld\n",n);
    }
    return 0;
}