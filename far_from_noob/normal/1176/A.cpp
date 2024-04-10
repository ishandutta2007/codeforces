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
        ll count=0;
        while(n!=1){
            if(n%2==0)n=n/2;
            else if(n%3==0)n=n*2/3;
            else if(n%5==0)n=n*4/5;
            else {count=-1;break;}
            count++;
        }
        cout<<count<<endl;
    }


    return 0;
}