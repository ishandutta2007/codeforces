#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define maxm 10011
#define maxn 511
#define pb push_back
#define ll unsigned long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{c=getchar();}
	while(c<='9'&&c>='0')	t=t*10+c-48,c=getchar();
	return t*f;
}
char s[52],hl[2001][52];
int n,m,ans;
bool vis[301];
inline void solve(int x)
{
	int cnt=0,no=0;
	For(i,1,m)
	{
		bool flag=0,f_no=0;
		For(j,1,n)
		{
			if(s[j]!='*'&&s[j]!=hl[i][j]){flag=1;f_no=1;}
			if(vis[hl[i][j]]&&(s[j]=='*')){flag=1;f_no=1;}
			if(hl[i][j]==x)	{flag=1;}
		}
		if(flag)	cnt++;
		if(f_no)	no++;
	}
	if(cnt==m&&no!=m)	ans++;
}
int main()
{
	n=read();
	scanf("\n%s",s+1);
	m=read();
	For(i,1,m)	scanf("\n%s",hl[i]+1);
	For(i,1,n)	if(s[i]!='*')	vis[s[i]]=1;
	For(i,'a','z')	
		if(vis[i])	continue;
			else solve(i);
	printf("%d\n",ans);
}