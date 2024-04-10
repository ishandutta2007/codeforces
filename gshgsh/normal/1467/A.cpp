#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N;int main(){cin>>T;while(T--){cin>>N;if(N==1){cout<<9<<endl;continue;}cout<<98;int a=9;For(i,3,N)cout<<a,a=(a+1)%10;cout<<endl;}return 0;}