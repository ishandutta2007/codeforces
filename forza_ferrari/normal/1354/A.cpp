#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,a,b,c,d;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        if(a<=b)
        {
            cout<<b<<'\n';
            continue;
        }
        a-=b;
        if(c<=d)
        {
            cout<<"-1\n";
            continue;
        }
        cout<<b+(a+c-d-1)/(c-d)*c<<'\n';
    }
    return 0;
}