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
        cin>>n>>q;
        ll a[n];
        fo(i,n)cin>>a[i];
        ll hatadiye[n],c[n],d[n],temp=a[0];
        fo(i,n-1){
            c[i]=temp;
            d[i]=a[i+1];
            if(temp>a[i+1]){hatadiye[i]=a[i+1];}
            else {
                hatadiye[i]=temp;
                temp=a[i+1];
            }

        }
        fo(i,q){
            cin>>k;
            if(k<n)
            cout<<c[k-1]<<" "<<d[k-1]<<endl;
            else cout<<temp<<" "<<hatadiye[(k-1)%(n-1) ]<<endl;
        }



    }

    return 0;
}