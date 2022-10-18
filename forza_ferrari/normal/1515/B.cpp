#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int t,n;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(4*(int)(sqrt(n>>2))*(int)(sqrt(n>>2))==n||2*(int)(sqrt(n>>1))*(int)(sqrt(n>>1))==n)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}