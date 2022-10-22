#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
#define MAXN 1000001
int N,f[MAXN][20][2],x,y;int cnt(int x,int y){return N/(1<<x)/(y?3:1);}
int main()
{
	cin>>N;while((1<<x+1)<=N)x++;f[1][x][0]=1;if((1<<x-1)*3<=N)f[1][x-1][1]=1,y=1;
	For(i,2,N)For(j,0,x)For(k,0,y){f[i][j][k]=1ll*f[i-1][j][k]*(cnt(j,k)-i+1)%P;if(j<x)f[i][j][k]=(f[i][j][k]+1ll*f[i-1][j+1][k]*(cnt(j,k)-cnt(j+1,k)))%P;if(k<y)f[i][j][k]=(f[i][j][k]+1ll*f[i-1][j][k+1]*(cnt(j,k)-cnt(j,k+1)))%P;}cout<<f[N][0][0]<<endl;return 0;
}