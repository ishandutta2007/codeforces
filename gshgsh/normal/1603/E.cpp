#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 211
int N,P,a1,f[MAXN][MAXN][MAXN],fc[MAXN],inv[MAXN];
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int dfs(int x,int sum,int now)
{
	if(f[x][sum][now]!=-1)return f[x][sum][now];if(!now&&x==N)return 0;if(!now)return 1ll*fc[N]*inv[N-x]%P;
	f[x][sum][now]=0;For(i,0,N-x)if(sum+i*now<=a1)if(now==1||x+i>=N+2-a1-now)f[x][sum][now]=(f[x][sum][now]+1ll*dfs(x+i,sum+i*now,now-1)*inv[i])%P;return f[x][sum][now];
}
int main()
{
	cin>>N>>P;fc[0]=1;For(i,1,N)fc[i]=1ll*fc[i-1]*i%P;inv[N]=pow(fc[N],P-2);FOR(i,N-1,0)inv[i]=1ll*inv[i+1]*(i+1)%P;
	int ans=0;for(a1=0;a1<=N+1;a1++){memset(f,-1,sizeof(f));ans=(ans+dfs(0,0,N+1-a1))%P;}cout<<ans<<'\n';return 0;
}