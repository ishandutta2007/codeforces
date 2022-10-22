#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N,K,M,a,b;
int main(){cin>>T;while(T--){cin>>N>>K>>M>>a>>b;if(K<M)swap(K,M);cout<<(M+(K-M)/2>=a&&(N-K)+(K-M)/2>=b?"YES\n":"NO\n");}return 0;}