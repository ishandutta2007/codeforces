#include<algorithm>
#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
#define P 998244353
#define MAXN 200001
int N,M,a[MAXN],sum[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
int pow(int a,int b){int ans=1;while(b)b&1?ans=1ll*ans*a%P:0,a=1ll*a*a%P,b>>=1;return ans;}
int main()
{
	N=get(),M=get();For(i,1,N)a[i]=get();sort(a+1,a+N+1);For(i,1,N)sum[i]=(sum[i-1]+a[i])%P;
	For(i,1,M)
	{
		int x=get(),y=get(),cnt=a+N-lower_bound(a+1,a+N+1,y)+1;
		put((1ll*max(cnt-x,0)*pow(cnt,P-2)%P*(sum[N]-sum[N-cnt]+P)%P+1ll*max(cnt+1-x,0)*pow(cnt+1,P-2)%P*sum[N-cnt]%P)%P),putchar('\n');
	}
	return 0;
}