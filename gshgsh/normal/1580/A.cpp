#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 401
int T,N,M,a[MAXN][MAXN],s[MAXN][MAXN],f[MAXN][MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int ask(int x1,int y1,int x2,int y2){return s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1];}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,N)For(j,1,M){char c;cin>>c;a[i][j]=c-'0';s[i][j]=a[i][j]+s[i][j-1]+s[i-1][j]-s[i-1][j-1];}
		For(i,1,M-3)For(j,i+3,M)f[i][j]=N*M+1;int ans=N*M+1;
		For(i,5,N)
		{
			For(j,1,M-3)For(k,j+3,M)f[j][k]=min(f[j][k],k-j-1-ask(i-4,j+1,i-4,k-1)+k-j-1-ask(i-1,j+1,i-1,k-1)+2-ask(i-3,j,i-2,j)+2-ask(i-3,k,i-2,k)+ask(i-3,j+1,i-2,k-1)),f[j][k]+=1-a[i-1][j]+1-a[i-1][k]-(k-j-1-ask(i-1,j+1,i-1,k-1))+ask(i-1,j+1,i-1,k-1)+k-j-1-ask(i,j+1,i,k-1);
			For(j,1,M-3)For(k,j+3,M)ans=min(ans,f[j][k]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}