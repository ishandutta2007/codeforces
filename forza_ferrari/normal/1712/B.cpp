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
            cout<<"1 ";
        for(int i=(n&1)+1;i<=n;i+=2)
            cout<<i+1<<" "<<i<<" ";
        cout<<'\n';
    }
    return 0;
}