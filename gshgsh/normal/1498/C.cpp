#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
#define MAXN 1001
int T,N,K,f[MAXN][MAXN];
int main(){cin>>T;while(T--){cin>>N>>K;For(i,0,N)For(j,0,K)f[i][j]=0;For(i,0,N)f[i][1]=1;For(j,2,K)For(i,0,N)f[i][j]=(i?f[i-1][j]+f[N-i][j-1]:1)%P;cout<<f[N][K]<<endl;}return 0;}