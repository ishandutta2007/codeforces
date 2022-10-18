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
        if(n&1)
        {
            cout<<"-1\n";
            continue;
        }
        cout<<"0 0 "<<n/2<<'\n';
    }
    return 0;
}