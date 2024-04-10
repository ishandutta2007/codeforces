#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <cstring>
#include <ctime>
#include <vector>
#define inf 1e9
#define ll long long
#define maxn 401000
#define y1 fuck
#define For(i,j,k) for(ll i=j;i<=k;i++)
#define Dow(i,j,k) for(ll i=k;i>=j;i--)
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
using namespace std;
int c,n,a[200100],tot[200100],nxt[200100];
int main()
{
	c=read();n=read();
	For(i,1,n)	a[i]=read();
	sort(a+1,a+n+1);
	For(i,1,n)	
		tot[a[i]]++;
	For(i,1,c)
	{
		if(tot[i])	nxt[i]=i;else nxt[i]=nxt[i-1];
	}
	For(co,1,c)
	{
		int now=c;
		bool alr=0;
		int tmp=nxt[now];
		while(now)
		{
			if(!tmp)	break;
			if((tmp<co)&&(!alr)&&(co<=now))	now-=co,alr=1;
			else
			{
				int nod=min(tot[tmp],now/tmp);
				now-=tmp*nod;
				tmp=min(tmp-1,nxt[now]);
			}	
		}
		if(now)	{writeln(co);return 0;}	
	}
	puts("Greed is good");
}