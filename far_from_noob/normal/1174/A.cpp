#include <iostream>
#include<bits/stdc++.h>
#define fo(i,n) for(int i=0;i<n;i++)
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin>>n;
    ll a[2*n];
    fo( i,2*n)cin>>a[i];
    sort(a,a+2*n);
    if(a[0]!=a[2*n-1])fo(i,2*n)cout<<a[i]<<" ";
    else cout<< -1;
    return 0;
    ll temp1=0,temp2=0;
    fo(i,n)temp1+=a[i];
    fo(i,n)temp2+=a[i+n];
    if(temp1!=temp2){
        fo(i,2*n)cout<<a[i]<<" ";
        return 0;
    }
    for(int i=0;i<n;i++){
        if(a[i]==a[i+n]);
        else {
            for(int j=i+1;j<2*n+i+1;j++)cout<<a[j%(2*n)]<<" ";
            return 0;
        }
    }
    cout<<-1;

    //cout << "Hello world!" << endl;
    return 0;
}