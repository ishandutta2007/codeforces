#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#define For(i,j,k) for(ll i=j;i<=k;++i)
#define Dow(i,j,k) for(ll i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
char s[2001];
int main()
{
	scanf("%s",s+1);
	int len=strlen(s+1);
	while(s[len]=='0')	len--;
	For(i,1,len/2)	if(s[i]!=s[len-i+1]){puts("NO");return 0;}
	puts("YES");
}