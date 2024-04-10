#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N;int main(){cin>>T;while(T--){cin>>N,cout<<N<<endl;For(i,1,N)cout<<i<<' ';cout<<endl;}return 0;}