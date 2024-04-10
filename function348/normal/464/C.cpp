#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long LL;

struct rec 
{ 
	LL x,l;
	rec(LL X=0,LL L=0) { x=X;l=L;}
};

const int N=100010;
const LL mo=1000000007;
char s[N];
int n,m;
char r[N];
char t[N];
int fr[N],la[N];
rec f[20];

LL exp(LL a,LL b)
{
	if (a==0)return 0;
	LL d=a,e=1;
	while (b)
	{
		if (b&1) e=(e*d)%mo;
		d=d*d%mo;
		b>>=1;
	}
	return e;
}
rec operator +(rec a,rec b) { return rec( (a.x*exp(10,b.l)%mo+b.x)%mo,(a.l+b.l)%(mo-1)); }
char getc()
{
	char ch;
	while ((ch=getchar())<=32);
	return ch;
}
int main()
{
	scanf("%s",s+1);int n=strlen(s+1);
	scanf("%d",&m);
	int now=0;
	for (int i=1;i<=m;i++)
	{
		r[i]=getc();
		getc();getc();
		fr[i]=now;
		while (1)
		{
			char ch=getchar();
			if (ch=='\n') break;
			t[now]=ch;
			now++;
		}
	}
	fr[m+1]=now;
	for (int i=0;i<=9;i++) f[i].x=i,f[i].l=1;
	for (int i=m;i>=1;i--)
	{
		rec x;
		x.l=x.x=0;
		for (int j=fr[i];j<=fr[i+1]-1;j++)
			x=x+f[t[j]-'0'];
		f[r[i]-'0']=x;
	}
	rec ans;
	for (int i=1;i<=n;i++) ans=ans+f[s[i]-'0'];
	printf("%d\n",ans);
	return 0;
}