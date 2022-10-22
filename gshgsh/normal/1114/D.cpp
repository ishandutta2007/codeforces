#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,j,N) for(int l=1;l<N;l++)for(int i=1,j=i+l;j<=N;i++,j++)
#define MAXN 5001
int N,M,a[MAXN],f[MAXN][MAXN];
int main(){cin>>N;int x,lst=0;For(i,1,N)cin>>x,x!=lst?a[++M]=x:0,lst=x;FOR(i,j,M)f[i][j]=a[i]==a[j]?f[i+1][j-1]+1:min(f[i+1][j],f[i][j-1])+1;cout<<f[1][M]<<endl;return 0;}