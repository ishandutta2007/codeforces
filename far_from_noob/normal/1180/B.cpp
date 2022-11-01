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
        int a[n],countpos=0;
        fo(i,n)cin>>a[i];
        int min=10000000,minindex=0;
        fo(i,n){
            if(a[i]>=0)a[i]=-a[i]-1;
        }
        if(n%2==1){fo(i,n){
            if(a[i]<min){min=a[i];minindex=i;}
        }
        a[minindex]=-a[minindex]-1;}
        fo(i,n)cout<<a[i]<<" ";


    }

    return 0;
}