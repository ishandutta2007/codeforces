#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define dd double
#define fo(i,n) for(int i=0;i<n;i++)




ll n,k,t,m,q,flag=0,countans=0;
int main() {
    cin>>n;
    cin>>m;
    int a[n];
    fo(i,n)cin>>a[i];
    fo(i,n){
        if(i==0)cout<<0<<" ";
        else {
            int temp[i-1],count=i;
            fo(j,i)temp[j]=a[j];
            sort(temp,temp+i-1);
            int m1=m-a[i];
            fo(j,i){
                if(temp[j]<=m1){
                    count--;
                    m1=m1-temp[j];
                }

            }
            cout<<count<<" ";
        }



    }

    return 0;
}