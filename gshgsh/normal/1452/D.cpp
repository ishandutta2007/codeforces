#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 998244353
#define MAXN 200001
int N,f[MAXN]={0,1};int pow(int a,int b){int ans=1;while(b)b&1?ans=1ll*ans*a%P:0,a=1ll*a*a%P,b>>=1;return ans;}
int main(){cin>>N;For(i,2,N)f[i]=(f[i-2]+f[i-1])%P;cout<<1ll*f[N]*pow(pow(2,P-2),N)%P<<endl;return 0;}