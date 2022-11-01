#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
 
 
using namespace std;
 
inline ll read()
{
	ll t=0,dp=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	dp=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-48,c=getchar();
	return t*dp;
}
inline void write(ll x){if(x<0)	{putchar('-');x=-x;}	if(x>=10)	write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
/*------------------------------------------------------------------------------------------------------*/

const int N=1e6+5;
int las=1,tot=1,t[N*2],T[N*2],rig[N*2];
int vis[N*2];
char qs[N],s[N];
int len,len1,tim,n;
struct node{int tr[26],mx,link;}	p[N*2];
inline void extend(int c)
{
	int New=++tot,pre=las;las=tot;
	p[New].mx=p[pre].mx+1;
	rig[New]=1;
	for(;pre&&p[pre].tr[c]==0;pre=p[pre].link)	p[pre].tr[c]=New;
	if(!pre)	p[New].link=1;
	else
	{
		int to=p[pre].tr[c];
		if(p[to].mx==p[pre].mx+1)	p[New].link=to;
		else
		{
			int tmp=++tot;
			p[tmp]=p[to];p[tmp].mx=p[pre].mx+1;
			p[New].link=p[to].link=tmp;
			for(;pre&&p[pre].tr[c]==to;pre=p[pre].link)	p[pre].tr[c]=tmp;
		}
	}
}
inline void topsort()
{
	For(i,1,tot)	t[p[i].mx]++;
	For(i,1,tot)	t[i]+=t[i-1];
	Dow(i,1,tot)	T[t[p[i].mx]--]=i;
	Dow(i,1,tot)	rig[p[T[i]].link]+=rig[T[i]];
}
inline int Que()
{
	++tim;
	int now=1,p1=0,ret=0;
	For(i,1,len1)
	{
		int c=qs[i]-'a';
		if(p[now].tr[c])	p1++,now=p[now].tr[c];
		else
		{
			while(now&&p[now].tr[c]==0)	now=p[now].link;
			if(now==0)	now=1,p1=0;else	p1=p[now].mx+1,now=p[now].tr[c];
		}
		if(i>=len1/2)
		{
			if(p1>=len1/2)	
			{
				int tmp=now;
				while(tmp&&p[p[tmp].link].mx>=len1/2)	tmp=p[tmp].link;
				if(vis[tmp]!=tim)	vis[tmp]=tim,ret+=rig[tmp];
			}
		}
	}
	return ret;
}
int main()
{
	scanf("\n%s",s+1);
	len=strlen(s+1);
	For(i,1,len)	extend(s[i]-'a');
	topsort();
	n=read();
	For(i,1,n)
	{
		scanf("\n%s",qs+1);
		len1=strlen(qs+1);
		For(i,1,len1)	qs[len1+i]=qs[i];
		len1<<=1;
		writeln(Que());
	}
}
/*
baabaabaaa
5
a
ba
baa
aabaa
aaba

*/