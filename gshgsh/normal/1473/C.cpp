#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
int T,N,K;int main(){cin>>T;while(T--){cin>>N>>K;For(i,1,K-(N-K+1))cout<<i<<' ';FOR(i,K,K-(N-K))cout<<i<<' ';cout<<endl;}return 0;}