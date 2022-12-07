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
#define N 1005
#define LL long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;
}
using namespace std;
const int mod=1000000007;
bitset<N>a[N],b[N],M;
int m,n,C[N][N],B[N];
bool use[N];
char s[N];
int main()
{
	re(m),re(n);
	for(int i=0;i<=m;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	B[0]=1;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=i;++j)
			B[i]=(B[i]+1ll*C[i-1][j-1]*B[i-j])%mod;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s);
		for(int j=0;j<m;++j)
			a[i][j]=s[j]-'0';
	}
	M.set();
	for(int i=0;i<m;++i)
	{
		b[i].set();
		for(int j=1;j<=n;++j)
			if(a[j][i])b[i]&=a[j];
			else b[i]&=a[j]^M;
	}
	int ans=1;
	for(int i=0;i<m;++i)if(!use[i])
	{
		int cnt=0;
		for(int j=0;j<m;++j)
			if(b[i]==b[j])
			{
				use[j]=1;
				++cnt;
			}
		ans=1ll*ans*B[cnt]%mod;
	}
	printf("%d\n",ans);
}