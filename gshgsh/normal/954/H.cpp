#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 100001
#define MAXM 5001
int N,a[MAXN],m[MAXN],inv[MAXN],ans[MAXN],f[MAXM][MAXM*2];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int main()
{
	N=get();For(i,2,N)a[i]=get();m[1]=1;For(i,2,N)m[i]=1ll*m[i-1]*a[i]%P,inv[i]=pow(2*m[i],P-2);
	FOR(i,N-1,1){f[i][2]=1ll*m[i+1]*m[i+1]%P;For(j,3,N-1<<1)f[i][j]=(f[i+1][j-2]+2ll*m[i+1]*m[i+j-1])%P;}
	For(i,1,N-1<<1)For(j,1,N-1)ans[i]=(ans[i]+m[i+j]+1ll*f[j][i]*(a[j+1]-1)%P*inv[j+1])%P;
	For(i,1,N-1<<1)cout<<ans[i]<<" \n"[i==(N-1<<1)];
}