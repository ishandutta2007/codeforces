#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,a,b,c;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        cout<<a+b+c<<" "<<b+c<<" "<<c<<'\n';
    }
    return 0;
}