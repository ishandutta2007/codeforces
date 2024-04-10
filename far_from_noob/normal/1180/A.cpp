#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define dd double
#define fo(i,n) for(int i=0;i<n;i++)
ll n,k,t,m,q,flag=0,count=0;
int main() {
    ios::sync_with_stdio(false);
    //cin>>t;
    t=1;
    while(t--){
        cin>>n;
        k=1,m=4;
        for(int i=1;i<n;i++) {
            k+=m;
            m+=4;
        }
        cout<<k;

    }

    return 0;
}