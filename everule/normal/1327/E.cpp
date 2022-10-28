#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const ll p=998244353;
int main(){
   int n;
   cin>>n;
   if(n==1){
       cout<<"10";
       return 0;
   }
   if(n==2){
       cout<<"180 10";
       return 0;
   }
   ll seq[n+1];
   ll powerof10[n+1];
   powerof10[0]=1;
   for(int i=1;i<=n;i++){
       powerof10[i]=10*powerof10[i-1];
       powerof10[i]%=p;
   }
   seq[n]=10;
   seq[n-1]=180;
   for(int i=1;i<n-1;i++){
       seq[i]=(n-i-1)*81;
       seq[i]*=powerof10[n-i-1];
       seq[i]%=p;
       seq[i]+=18*powerof10[n-i];
       seq[i]%=p;
   }
   for(int i=1;i<=n;i++){
       cout<<seq[i]<<" ";
   }
   return 0;
}