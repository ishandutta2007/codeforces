#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N,K;
int main(){cin>>T;while(T--){cin>>N>>K;cout<<N-K+K/2<<endl;For(i,(K+1)/2,K-1)cout<<i<<' ';For(i,K+1,N)cout<<i<<' ';cout<<endl;}return 0;}