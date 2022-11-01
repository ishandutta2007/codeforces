#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define dd double
#define fo(i,n) for(int i=0;i<n;i++)
int min(int a,int b){
if(a>b)return b;
else return a;
}
int max(int a,int b){
if(a>b)return a;
else return b;
}
int swap(int a,int b){
int temp=a;
a=b;
b=temp;
}
ll po(int x){
    return (ll)pow(2,x);
}
ll n,k,t,m,q,x,X;
int main() {
    //cin>>t;
    t=1;
    while (t--){
        cin>>n;
        ll a[n],c[6];
        c[0]=0,c[2]=0,c[3]=0,c[4]=0,c[5]=0,c[1]=0;
        fo(i,n){
            cin>>a[i];
            if(a[i]==4)c[0]++;
            if(a[i]==8&& c[0]>c[1])c[1]++;
            if(a[i]==15&& c[2]<c[1])c[2]++;
            if(a[i]==16&& c[3]<c[2])c[3]++;
            if(a[i]==23&& c[4]<c[3])c[4]++;
            if(a[i]==42&& c[5]<c[4])c[5]++;
        }
        sort(c,c+6);
        ll count=0;
        //cout<<c[0]<<c[1]<<c[2]<<c[3]<<c[4]<<c[5];
        for(int i=1;i<6;i++)count+=c[i]-c[0];
        cout<<n- c[0]*6;

    }


    return 0;
}