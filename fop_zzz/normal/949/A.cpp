#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e9
#define int ll
using namespace std;
inline int read()
{
	int t=0,dp=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	dp=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-'0',c=getchar();
	return t*dp;
}
inline void write(int x){if(x>=10)	write(x/10);putchar(x%10+'0');}
inline void writeln(int x){write(x);puts("");}
inline void write_p(int x){write(x);putchar(' ');}
char s[1000010];
int z[1000010],dp[1000010],odk[1000010],z0[1000010],d1,d0,d,l,bj[1000010],sum;
void dfs(int x){z[++d]=x;if (dp[x])dfs(dp[x]);}
signed main(){
	scanf("%s",s+1);
	l=strlen(s+1);
	for (int i=1;i<=l;i++)
		if (s[i]=='0'){ 
			if (!d1)bj[i]=1,sum++;else dp[odk[d1]]=i,d1--;z0[++d0]=i;
	}
	else
	{ 
		if (!d0){puts("-1");return 0;}else dp[z0[d0]]=i,d0--;odk[++d1]=i;	
	}
	if (d1){puts("-1");return 0;}
	writeln(sum);
	for (int i=1;i<=l;i++)
		if (bj[i]){
		d=0;dfs(i);write(d);for (int j=1;j<=d;j++)putchar(' '),write(z[j]);puts("");
	}
}