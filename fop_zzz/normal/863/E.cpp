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
int n;
struct line {int l,r,num;}	ln[500001];
inline bool cmp(line x,line y){return x.l!=y.l?x.l<y.l:x.r<y.r;}
inline void out(int x){printf("%d\n",ln[x].num);exit(0);}
int main()
{
	n=read();
	For(i,1,n)
		ln[i].l=read(),ln[i].r=read(),ln[i].num=i;
	sort(ln+1,ln+n+1,cmp);
	For(i,2,n)
	{
		if(ln[i].r<=ln[i-1].r)	out(i);	else	if(ln[i].l==ln[i-1].l)	out(i-1);
		if(i!=n)
			if(ln[i+1].l-1<=ln[i-1].r)
				if(ln[i+1].r>=ln[i].r)	out(i);
	}
	puts("-1");
}