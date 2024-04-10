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
    cin>>t;
    //t=1;
    while (t--){
        cin>>n;
        ll a[n],c=0,c1=0,c2=0;
        fo(i,n){
        cin>>a[i];
        if(a[i]%3==0)c++;
        else if(a[i]%3==1)c1++;
        else c2++;

        }cout<<c+min(c1,c2)+ abs(c1-c2)/3<<endl;

    }


    return 0;
}