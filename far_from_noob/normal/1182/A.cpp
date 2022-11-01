#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define dd double
#define fo(i,n) for(int i=0;i<n;i++)
//vector<int>v[200005];

using namespace std;
ll n,t,m,k,x,y;

int main()
{
    t=1;
    //cin>>t;
    while(t--){
        cin>>n;
        if(n%2==0)cout<<(ll)pow(2,n/2);
        else cout<<0;;

    }
    return 0;
}