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
#define N 705
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
char s[N];
int n,f[N][10][N][2];
void add(int &a,int b)
{
	a=a+b<mod?a+b:a+b-mod;
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=9;++i)f[0][i][0][0]=1;
	for(int i=0;i<n;++i)
		for(int j=1;j<=9;++j)
			for(int k=0;k<=i;++k)
				for(int l=0;l<2;++l)
					for(int m=0;m<=(l?9:(s[i+1]-48));++m)
						add(f[i+1][j][k+(m>=j)][l|(m<s[i+1]-48)],f[i][j][k][l]);
	int ans=0;
	for(int i=1;i<=9;++i)
	{
		int t=1;
		for(int j=1;j<=n;++j,t=(t*10ll+1)%mod)
			ans=(ans+1ll*t*(f[n][i][j][0]+f[n][i][j][1]))%mod;
	}
	printf("%d\n",ans);
}