#include<iostream>
#include<cstring>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 1001
int N,a[MAXN],f[MAXN][MAXN],pre[MAXN][MAXN];
void print(int x,int y){if(!x)return;int p=pre[x][y]/(N+1),q=pre[x][y]%(N+1);print(p,q);if(x-(y!=0)&1)cout<<(x==p?q:x)<<endl;else if(!y&&!q)cout<<x-1<<' '<<x<<endl;else if(!y&&q)cout<<q<<' '<<x<<endl;else if(y&&!q){For(i,p+1,x)if(i!=y)cout<<i<<' ';cout<<endl;}else if(q!=y)cout<<q<<' '<<x<<endl;else cout<<x-1<<' '<<x<<endl;}
int main()
{
	cin>>N;For(i,1,N)cin>>a[i];memset(f,0x3f,sizeof(f));f[0][0]=0;
	For(i,0,N)For(j,0,max(i-1,0))
	if(!j)
	{
		if(i+3<=N)f[i][0]+max(a[i+2],a[i+3])<f[i+3][i+1]?f[i+3][i+1]=f[i][0]+max(a[i+2],a[i+3]),pre[i+3][i+1]=i*(N+1):0,f[i][0]+max(a[i+1],a[i+3])<f[i+3][i+2]?f[i+3][i+2]=f[i][0]+max(a[i+1],a[i+3]),pre[i+3][i+2]=i*(N+1):0;
		if(i+2<=N)f[i][0]+max(a[i+1],a[i+2])<f[i+2][0]?f[i+2][0]=f[i][0]+max(a[i+1],a[i+2]),pre[i+2][0]=i*(N+1):0;else f[i][0]+a[i+1]<f[i+1][0]?f[i+1][0]=f[i][0]+a[i+1],pre[i+1][0]=i*(N+1):0;
	}
	else
	{
		if(i+2<=N)f[i][j]+max(a[i+1],a[i+2])<f[i+2][j]?f[i+2][j]=f[i][j]+max(a[i+1],a[i+2]),pre[i+2][j]=i*(N+1)+j:0,f[i][j]+max(a[j],a[i+2])<f[i+2][i+1]?f[i+2][i+1]=f[i][j]+max(a[j],a[i+2]),pre[i+2][i+1]=i*(N+1)+j:0;
		if(i+1<=N)f[i][j]+max(a[j],a[i+1])<f[i+1][0]?f[i+1][0]=f[i][j]+max(a[j],a[i+1]),pre[i+1][0]=i*(N+1)+j:0;else f[i][j]+a[j]<f[i][0]?f[i][0]=f[i][j]+a[j],pre[i][0]=i*(N+1)+j:0;
	}
	cout<<f[N][0]<<endl;print(N,0);return 0;
}