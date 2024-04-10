#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N;int main(){cin>>T;while(T--){cin>>N;For(i,N+1,2*N)cout<<i*2<<' ';cout<<endl;}return 0;}