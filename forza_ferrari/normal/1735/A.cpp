#include<iostream>
#include<cstdio>
using namespace std;
int t,n,ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<(n-3)/3-1<<'\n';
    }
    return 0;
}