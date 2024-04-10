#include<bits/stdc++.h>
#define fir first
#define sec second
using namespace std;
typedef long long ll;

const int mod = 998244353;
const int maxn = 1010;

int n,K,mxa;
int a[maxn];

inline int MOD(int x){return x<mod ? x:x-mod;}
inline int Mod(int x){return x<0 ? x+mod:x;}

void input()
{
	int i;

	scanf("%d%d",&n,&K);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1,a+n+1);mxa=a[n]-a[1];
}

int f[maxn][maxn],g[maxn][maxn];
int calc(int Lim)
{
	int i,j,k;

	for(i=1;i<=K;i++) g[0][i]=0;
	for(i=1;i<=n;i++) f[i][1]=1,g[i][1]=g[i-1][1]+1;
	for(k=2;k<=K;k++)
	{
		j=0;
		for(i=1;i<=n;i++)
		{
			for(;a[i]-a[j+1] >= Lim;j++);//j+1 is able to trans
			f[i][k]=g[j][k-1];//cerr<<f[i][k]<<' ';
			g[i][k]=MOD(g[i-1][k]+f[i][k]);
		}//cerr<<endl;
	}
	return g[n][K];
}

void solve()
{
	int i,t,fans=0;

	for(i=1;;i++)
	{
		t=calc(i);if(!t) break;
		fans=MOD(fans+t);
	}
	printf("%d\n",fans);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("inp.in","r",stdin);
	freopen("oup.out","w",stdout);
	#endif
	
	input();
	solve();

	return 0;
}