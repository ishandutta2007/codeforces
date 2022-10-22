#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 2001
int N,a[MAXN];ll f[MAXN][MAXN]; 
int main(){cin>>N;For(i,1,N)cin>>a[i];sort(a+1,a+N+1);For(l,1,N-1)for(int i=1,j=i+l;j<=N;i++,j++)f[i][j]=min(f[i][j-1],f[i+1][j])+a[j]-a[i];cout<<f[1][N]<<endl;return 0;}