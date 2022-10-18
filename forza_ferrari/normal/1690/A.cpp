#include<iostream>
#include<cstdio>
using namespace std;
int t,n;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<n/3+(n%3>=2)<<" "<<n/3+(n%3>=1)+1<<" "<<n/3-1<<'\n';
    }
    return 0;
}