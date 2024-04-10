#include<cstdio>
#include<iostream>
using namespace std;
int n,x,mx=0;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x,mx=max(mx,x);
    cout<<(x^mx);
    return 0;
}