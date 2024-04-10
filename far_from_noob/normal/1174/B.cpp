#include <iostream>
#include<bits/stdc++.h>
#define fo(i,n) for(int i=0;i<n;i++)
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin>>n;
    int a[n];
    int odd=0,even=0;
    fo(i,n){cin>>a[i];if(a[i]%2==1)odd++;else even++;}
    if(odd==0 || even==0)fo(i,n)cout<<a[i]<<" ";
    else {
        sort(a,a+n);
        fo(i,n)cout<<a[i]<<" ";
    }


    //cout << "Hello world!" << endl;
    return 0;
}