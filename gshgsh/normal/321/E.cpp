#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define INF 0x3fffffff
#define MAXN 4001
int N,K,s[MAXN][MAXN],f[MAXN],g[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void solve(int l,int r,int x,int y)
{
	int k=x,mid=l+r>>1;if(l>r)return;For(i,x+1,min(y,mid-1))if(s[mid][mid]-s[i][mid]*2+s[i][i]+g[i]<s[mid][mid]-s[k][mid]*2+s[k][k]+g[k])k=i;
	f[mid]=s[mid][mid]-s[k][mid]*2+s[k][k]+g[k];solve(l,mid-1,x,k);solve(mid+1,r,k,y);
}
int main()
{
	N=get(),K=get();For(i,1,N)For(j,1,N)s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+get();
	For(i,1,N)f[i]=INF;while(K--){For(i,1,N)g[i]=f[i],f[i]=INF;solve(1,N,0,N-1);}cout<<f[N]/2<<'\n';return 0;
}