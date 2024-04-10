#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<sstream>
using namespace std;
int a[1234],b[1234];
bool prime(int f)
 {
    for(long i=2;i*i<=f;i++){
	
      if(f%i==0) return false;}
    return true;
 }

 int main()
 {
    for(int i=2;i<=1000;i++) {
        if(!a[i]){
 for(int j=i+i;j<=1000;j+=i){
a[j]=1;}
    }
     }
     int g=0;
     for(int i=2;i<=1000;i++) {
        if(!a[i]) a[g++]=i;
     }
     for(int i=2;i<=g;i++){
        int t=a[i]+a[i-1]+1;
        if(prime(t)) b[t]=1;
     }
     for(int i=1;i<=1000;i++) {
        b[i]+=b[i-1];
}
    int n,k;
     cin>>n>>k;
    if(b[n]>=k) cout<<"YES";
        else cout<<"NO";
    return 0;
}