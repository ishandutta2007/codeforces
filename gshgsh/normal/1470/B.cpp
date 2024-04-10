#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 300001
#define MAXM 1000001
int T,N,M,a[MAXN],tot,prm[MAXM],f[MAXM],cnt[MAXM];bool Not[MAXM];
ll get(){ll x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
int main()
{
	N=MAXM-1;For(i,2,N)if(!Not[i]){prm[++tot]=i;f[i]=i;for(ll j=1ll*i*i;j<=N;j+=i)Not[j]=1,f[j]=i;}T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();int ans=0,cnt2=0;
		For(i,1,N)
		{
			int x=a[i];bool flag=0;while(x>1){int tmp=f[x];while(a[i]%(1ll*tmp*tmp)==0)x/=tmp*tmp,a[i]/=tmp*tmp;if(x%tmp==0)x/=tmp,flag=1;}
			ans=max(ans,++cnt[a[i]]);if(flag)cnt2+=cnt[a[i]]&1?1-cnt[a[i]]:cnt[a[i]];else cnt2++;
		}
		M=get();For(i,1,M){ll x=get();if(!x)put(ans);else put(max(cnt2,ans));putchar('\n');}For(i,1,N)cnt[a[i]]--;
	}
	return 0;
}