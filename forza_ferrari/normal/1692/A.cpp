#include<iostream>
#include<cstdio>
using namespace std;
int t,a,b,c,d;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        cout<<(b>a)+(c>a)+(d>a)<<'\n';
    }
    return 0;
}