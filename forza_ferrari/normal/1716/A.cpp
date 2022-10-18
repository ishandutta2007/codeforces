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
        if(n==1)
            cout<<"2\n";
        else
            cout<<(n+2)/3<<'\n';
    }
    return 0;
}