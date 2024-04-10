#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 100001
int T,N,a[MAXN],fc[MAXN],inv[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int getc(){char c=getchar();while(c!='0'&&c!='1')c=getchar();return c-'0';}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int C(int a,int b){return 1ll*fc[a]*inv[b]%P*inv[a-b]%P;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=getc();fc[0]=1;For(i,1,N)fc[i]=1ll*fc[i-1]*i%P;inv[N]=pow(fc[N],P-2);FOR(i,N-1,0)inv[i]=1ll*inv[i+1]*(i+1)%P;
		int x=0,y=0;For(i,1,N)if(!a[i])x++;else if(a[i-1])x++,y++,a[i]=0;cout<<C(x,y)<<endl;
	}
	return 0;
}