#include<iostream>
#include<cstdio>
using namespace std;
int t,a,b;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<(a? a+(b<<1)+1:1)<<'\n';
    }
    return 0;
}