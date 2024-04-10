#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 2001
using namespace std;
const int mod=1073741824;
int a,b,c,ans;
int cnt,p[N],miu[N],f[N][N],gcd[N][N];
bool vis[N];
void init()
{
	miu[1]=1;
	for(int i=2;i<N;++i)
	{
		if(!vis[i])
		{
			p[++cnt]=i;
			miu[i]=-1;
		}
		for(int j=1,k;j<=cnt && (k=i*p[j])<N;++j)
		{
			vis[k]=1;
			if(i%p[j])miu[k]=-miu[i];
			else {miu[k]=0;break;}
		}
	}
}
int GCD(int a,int b)
{
	if(a==b)return a;
	if(gcd[a][b])return gcd[a][b];
	if(a>b)swap(a,b);
	return gcd[a][b]=GCD(a,b-a);
}
int F(int a,int b)
{
	if(f[a][b])return f[a][b];
	for(int i=1;i<=a;++i)
		if(GCD(i,b)==1)
			f[a][b]+=a/i;
	return f[a][b];
}
int main()
{
	init();
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;++i)
	{
		int tmp=0;
		for(int j=1;j<=b;++j)
			if(miu[j] && GCD(i,j)==1)
				tmp=(tmp+1ll*miu[j]*F(b/j,i)*F(c/j,i))%mod;
		ans=(ans+1ll*a/i*tmp)%mod;
	}
	printf("%d\n",ans);
}