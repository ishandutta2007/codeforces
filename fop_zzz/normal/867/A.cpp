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
int n,cnt1,cnt2;
char s[2001];
int main()
{
	scanf("%d",&n);
	scanf("\n%s",s+1);
	For(i,1,n-1)
		if(s[i]=='S'&&s[i+1]=='F')	cnt1++;
		else	if(s[i]=='F'&&s[i+1]=='S')	cnt2++;
	if(cnt1>cnt2)	puts("YES");else puts("NO");
}