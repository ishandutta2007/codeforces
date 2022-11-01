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
using namespace std;
inline int read()
{
	int t=0,f=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	f=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-'0',c=getchar();
	return t*f;
}
inline void write(int x){if(x>=10)	write(x/10);putchar(x%10+'0');}
inline void writeln(int x){write(x);puts("");}
inline void write_p(int x){write(x);putchar(' ');}
int n,ans,mx,tmp;
int dp[26][26][5001];
char s[20001];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	For(i,1,n)	s[i+n]=s[i];
	For(i,1,n)
		For(j,1,n-1)//ii+j
			dp[s[i]-'a'][s[i+j]-'a'][j]++;
	For(p1,0,25)
	{
		mx=0;
		For(k,1,n-1)
		{
			tmp=0;
			For(p2,0,25)
				if(dp[p1][p2][k]==1)	tmp++;
			mx=max(mx,tmp);
		}
		ans+=mx;
	}
	printf("%.20lf",1.0*ans/n);
}