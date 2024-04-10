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
char s[20001];
int f[20001][4];
int main()
{
	scanf("%s",s+1);
	int len=strlen(s+1);
	For(i,1,len)
	{
		f[i][0]=f[i-1][0]+(s[i]=='a');
		f[i][1]=max(f[i-1][0],f[i-1][1])+(s[i]=='b');
		f[i][2]=max(max(f[i-1][0],f[i-1][1]),f[i-1][2])+(s[i]=='a');
	}
	printf("%d\n",max(f[len][0],max(f[len][1],f[len][2])));
}