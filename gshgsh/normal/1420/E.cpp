#include<algorithm>
#include<iostream>
#include<cstring>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 81
int N,K,a[MAXN],f[MAXN][MAXN][MAXN*MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,N)if(get())a[++K]=i;if(!K){For(i,0,N*(N-1)/2)cout<<"0 ";cout<<'\n';return 0;}int sum=(N-K)*(N-K-1)/2;
	memset(f,0x3f,sizeof(f));For(i,1,N)f[1][i][abs(i-a[1])]=(i-1)*(i-2)/2;
	For(i,1,K-1)For(j,1,N)For(k,0,N*K)if(f[i][j][k]<1e9)For(l,j+1,N)f[i+1][l][k+abs(l-a[i+1])]=min(f[i+1][l][k+abs(l-a[i+1])],f[i][j][k]+(l-j-1)*(l-j-2)/2);
	int ans=1e9;For(i,0,N*(N-1)/2){For(j,1,N)ans=min(ans,f[K][j][i]+(N-j)*(N-j-1)/2);cout<<sum-ans<<" \n"[i==N*(N-1)/2];}
}