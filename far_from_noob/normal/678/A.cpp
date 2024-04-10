#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define dd double
#define endl "\n"
#define fo(i,n) for(int i=0;i<n;i++)
ll n,k,t,m,q,flag=0,count=0;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //cin>>t;
    t=1;
    while(t--){
            cin>>n>>k;
            if(n%k==0)cout<<n+k;
            else cout<<(n/k + 1)*k;
    }

    return 0;
}