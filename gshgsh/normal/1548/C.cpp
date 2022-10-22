#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define I3 333333336
#define MAXN 1000001
int N,M,fc[MAXN*3],inv[MAXN*3],f[MAXN*3][3];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int C(int a,int b){if(b>a||b<0)return 0;return 1ll*fc[a]*inv[b]%P*inv[a-b]%P;}
int main()
{
	N=get(),M=get();fc[0]=1;For(i,1,N*3)fc[i]=1ll*fc[i-1]*i%P;inv[N*3]=pow(fc[N*3],P-2);FOR(i,N*3-1,0)inv[i]=1ll*inv[i+1]*(i+1)%P;
	f[0][0]=f[0][1]=f[0][2]=N;For(i,1,N*3-1)f[i][0]=(C(N*3,i+1)-2ll*f[i-1][0]-f[i-1][1]+P*3ll)*I3%P,f[i][1]=(f[i][0]+f[i-1][0])%P,f[i][2]=(f[i][1]+f[i-1][1])%P;
	while(M--){int x=get();cout<<(f[x][0]+C(N*3,x))%P<<'\n';}return 0;
}