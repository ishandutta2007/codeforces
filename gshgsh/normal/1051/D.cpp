#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 998244353
#define MAXN 1001
int N,M,f[MAXN][MAXN*2][2][2],upd[2][2][2][2];
void init()
{
	upd[0][0][0][0]=0;upd[0][0][0][1]=1;upd[0][0][1][0]=1;upd[0][0][1][1]=1;upd[0][1][0][0]=0;upd[0][1][0][1]=0;upd[0][1][1][0]=2;upd[0][1][1][1]=0;
	upd[1][0][0][0]=0;upd[1][0][0][1]=2;upd[1][0][1][0]=0;upd[1][0][1][1]=0;upd[1][1][0][0]=1;upd[1][1][0][1]=1;upd[1][1][1][0]=1;upd[1][1][1][1]=0;
	For(i,0,1)For(j,0,1)f[1][1+(i^j)][i][j]=1;
}
int main()
{
	cin>>N>>M;init();For(i,2,N)For(j,1,2*i)For(k,0,1)For(l,0,1)For(m,0,1)For(n,0,1)if(j>=upd[m][n][k][l])f[i][j][k][l]=(f[i][j][k][l]+f[i-1][j-upd[m][n][k][l]][m][n])%P;
	cout<<((f[N][M][0][0]+f[N][M][0][1])%P+(f[N][M][1][0]+f[N][M][1][1])%P)%P<<endl;return 0;
}