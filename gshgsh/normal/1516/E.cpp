#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 401
int N,K,f[MAXN][MAXN],C[MAXN][MAXN],fc[MAXN],inv[MAXN],ans[2]={1};int getC(int N,int M){int ans=1;For(i,N-M+1,N)ans=1ll*ans*i%P;return 1ll*ans*inv[M]%P;}int pow(int a,int b){int ans=1;while(b)b&1?ans=1ll*ans*a%P:0,a=1ll*a*a%P,b>>=1;return ans;}
int main()
{
	cin>>N>>K;f[0][0]=C[0][0]=fc[0]=1;For(i,1,K*2){fc[i]=1ll*fc[i-1]*i%P;f[i][0]=C[i][0]=1;For(j,1,i)f[i][j]=(f[i-1][j]+1ll*(i-1)*f[i-1][j-1])%P,C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;}inv[K*2]=pow(fc[K*2],P-2);FOR(i,K*2-1,0)inv[i]=1ll*inv[i+1]*(i+1)%P;
	For(j,1,K){For(i,1,min(N,j*2)){int sum=0;For(k,0,i)sum=(sum+1ll*(k&1?-1:1)*C[i][k]*f[i-k][j]%P+P)%P;ans[j&1]=(ans[j&1]+1ll*sum*getC(N,i))%P;}cout<<ans[j&1]<<' ';}return 0;
}