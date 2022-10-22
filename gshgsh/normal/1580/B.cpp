#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 101
int N,M,K,P,f[MAXN][MAXN][MAXN],C[MAXN][MAXN];bool vis[MAXN][MAXN][MAXN];
int solve(int x,int y,int z){if(x+1<z*2||z>x)return 0;if(!x)return !z;if(vis[x][y][z])return f[x][y][z];if(y>M&&z)return 0;vis[x][y][z]=1;For(i,0,x-1)For(j,0,z-(y==M))f[x][y][z]=(f[x][y][z]+1ll*C[x-1][i]*solve(i,y+1,j)%P*solve(x-1-i,y+1,z-(y==M)-j))%P;return f[x][y][z];}
int main(){cin>>N>>M>>K>>P;For(i,0,N){C[i][0]=1;For(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;}cout<<solve(N,1,K)<<'\n';return 0;}