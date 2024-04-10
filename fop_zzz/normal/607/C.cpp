#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define For(i,j,k) for(int i=j;i<=k;++i)
#define Dow(i,j,k) for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e9
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
    while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
    return t*f;
}
int n;
char a[2000001],b[2000001];
inline void gg(){puts("NO");exit(0);}
inline char change(char t)
{
	if(t=='N')	return 'S';
	if(t=='S')	return 'N';
	if(t=='E')	return 'W';
	if(t=='W')	return 'E';
}
unsigned ll ha[2000001],hb[2000001],pw[2000001];
unsigned ll bas=47;
int main()
{
	n=read();n--;
	scanf("\n%s",a+1);
	scanf("\n%s",b+1);
	reverse(b+1,b+n+1);
	For(i,1,n)	b[i]=change(b[i]);
	unsigned ll hash=0;
	pw[0]=1;
	For(i,1,n)	pw[i]=pw[i-1]*bas;
	For(i,1,n)
	{
		hash=hash*bas+a[i];
		ha[i]=hash;
	}
	hash=0;
	For(i,1,n)
	{
		hash=hash*bas+b[i];
		hb[i]=hash;
	}
	For(i,1,n)	if(ha[n]-ha[n-i]*pw[i]==hb[i])	{puts("NO");return 0;}
	puts("YES");
}