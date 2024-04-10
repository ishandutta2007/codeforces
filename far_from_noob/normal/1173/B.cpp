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
int n,k,t,m,q,flag=0,count=0;
int main() {
    cin>>n;
    t= n/2+1;
    cout<<t<<endl;
    fo(i,n){
        if(i%2==0)cout<<i/2+1<<" "<<i/2+1<<endl;
        else cout<<i/2+2<<" " <<i/2+1<<endl;
    }


    return 0;
}