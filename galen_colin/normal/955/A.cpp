#include<bits/stdc++.h>
using namespace std;
int c(int n,int k){return (n+k-1)/k;}
int main(){
int h,m;cin>>h>>m;
double ans=0;
int hh,dd,cc,nn;
cin>>hh>>dd>>cc>>nn;
ans = c(hh,nn)*cc;
if(h<20)hh+=dd*60*(19-h),hh+=dd*(60-m);
ans=min(ans,0.8*(c(hh,nn)*cc));
cout<<setprecision(7)<<fixed<<ans;}