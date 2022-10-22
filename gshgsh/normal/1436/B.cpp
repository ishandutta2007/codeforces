#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N;int main(){cin>>T;while(T--){cin>>N;For(i,1,N)For(j,1,N)cout<<(j==i||j==i%N+1)<<(j==N?'\n':' ');}return 0;}