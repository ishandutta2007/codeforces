#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N,K;int main(){cin>>T;while(T--){cin>>N>>K;For(i,1,N)cout<<char('a'+i%3);cout<<endl;}return 0;}