#include<iostream>
#include<cstdio>
using namespace std;
#define P 1000000007
int T,N,K;int pow(int a,int b){int ans=1;while(b)b&1?ans=1ll*ans*a%P:0,a=1ll*a*a%P,b>>=1;return ans;}int main(){cin>>T;while(T--)cin>>N>>K,cout<<pow(N,K)<<endl;return 0;}