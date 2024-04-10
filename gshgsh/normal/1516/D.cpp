#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int N,M,K,a[MAXN],f[MAXN][20],tot,prm[MAXN],Div[MAXN],pos[MAXN];bool Not[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	N=get(),M=get();For(i,1,N)K=max(K,a[i]=get());For(i,2,K){if(!Not[i])prm[++tot]=i,Div[i]=i,pos[i]=N;for(int j=1;j<=tot&&i*prm[j]<=K;j++){Not[i*prm[j]]=1;Div[i*prm[j]]=prm[j];if(i%prm[j]==0)break;}}
	f[N+1][0]=N;FOR(i,N,1){f[i][0]=f[i+1][0];int x=a[i];while(x>1)x/Div[x]%Div[x]?f[i][0]=min(f[i][0],pos[Div[x]]),pos[Div[x]]=i-1:0,x/=Div[x];}For(j,1,19){For(i,1,N)f[i][j]=f[f[i][j-1]+1][j-1];f[N+1][j]=N;}
	For(i,1,M){int l=get(),r=get();int x=l,ans=0;FOR(j,19,0)if(f[x][j]<r)x=f[x][j]+1,ans+=1<<j;cout<<ans+1<<endl;}return 0;
}