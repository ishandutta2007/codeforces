#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n&1)
        {
            puts("2");
            continue;
        }
        int a=2,b=n;
        while(b&1^1)
        {
            a<<=1;
            b>>=1;
        }
        if(a>1&&a<=2e9&&n>=a*(a+1)/2)
            cout<<a<<'\n';
        else if(b>1&&b<=2e9&&n>=b*(b+1)/2)
            cout<<b<<'\n';
        else
            cout<<"-1\n";
    }
    return 0;
}