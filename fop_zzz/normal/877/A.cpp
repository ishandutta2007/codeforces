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
#define ll  long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{c=getchar();}
	while(c<='9'&&c>='0')	t=t*10+c-48,c=getchar();
	return t*f;
}
char s[30001];
int flag1;
int main()
{
	scanf("%s",s+1);
	int len=strlen(s+1);
	For(i,1,len-5)
	{
		if(s[i]=='N'&&s[i+1]=='i'&&s[i+2]=='k'&&s[i+3]=='i'&&s[i+4]=='t'&&s[i+5]=='a')	flag1++;
	}
	For(i,1,len-3)
	{
		if(s[i]=='O'&&s[i+1]=='l'&&s[i+2]=='y'&&s[i+3]=='a')	flag1++;
	}
	For(i,1,len-4)
	{
		if(s[i]=='D'&&s[i+1]=='a'&&s[i+2]=='n'&&s[i+3]=='i'&&s[i+4]=='l')	flag1++;
	}
	For(i,1,len-4)
	{
		if(s[i]=='S'&&s[i+1]=='l'&&s[i+2]=='a'&&s[i+3]=='v'&&s[i+4]=='a')	flag1++;
	}
	For(i,1,len-2)
	{
		if(s[i]=='A'&&s[i+1]=='n'&&s[i+2]=='n')	flag1++;
	}
	if(flag1==1)	puts("YES");else puts("NO");
}