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
    int x,y,z;
    cin>>x>>y>>z;
    if(z==0&&x==y){cout<<0;return 0;}
    if(x>y+z){cout<<"+";return 0;}
    if(y>x+z){cout<<"-"; return 0;}
    cout<<"?";


    return 0;
}