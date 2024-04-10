#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N;int main(){cin>>T;while(T--){cin>>N;For(i,1,N)cout<<i%N+1<<' ';cout<<'\n';}return 0;}