#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 100010
#define int long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
queue<int> a,b,c;
set<int> s;
int cnt,x[N],y[N],dd[N];
int n,ta,tb,type[N],used[N],dy[N],dw[N];
int fix(char c)
{
	return c<='9'?c-'0':c-'a'+10;
}
void pri(int c)
{
	char tmp[15];
	int m=0;
	for(int i=c;i;i/=37)tmp[++m]=i%37-1;
	for(int i=m;i;--i)
		putchar(tmp[i]<=9?tmp[i]+'0':tmp[i]+'a'-10);
	putchar(' ');
}
main()
{
	re(n);
	for(int i=1;i<=n;++i)
	{
		char tmp[10];
		scanf("%s",tmp+1);
		int m=strlen(tmp+1);
		for(int j=1;j<=m;++j)
			dy[i]=dy[i]*37+fix(tmp[j])+1;
		s.insert(dy[i]);
		for(int j=1;j<=m;++j)
			if(tmp[j] <= '9')
				dw[i]=dw[i]*10+tmp[j]-'0';
			else 
			{
				dw[i]=-1;
				break;
			}
		if(tmp[1]=='0' || dw[i]>n)dw[i]=-1;
		m=0;
		for(int j=i;j;j/=10)tmp[++m]=j%10;
		for(int j=m;j;--j)
			dd[i]=dd[i]*37+tmp[j]+1;
		if(~dw[i])
			used[dw[i]]=i;
		re(type[i]);
		if(type[i])++ta;
		else ++tb;
	}
/*	for(int i=1;i<=n;++i)
		cerr<<dw[i]<<" ";
	puts("");*/
	for(int i=1;i<=n;++i)
	{	
		if(!used[i])	
			c.push(i);
		if(type[i] && ~dw[i] && dw[i]>ta)
			a.push(i);
		if(!type[i] && ~dw[i] && dw[i]<=ta)
			b.push(i);
	} 
	for(int i=1;i<=n;++i)
	{
		if(type[i] && !~dw[i])
			a.push(i);
		if(!type[i] && !~dw[i])
			b.push(i);
	}
	if(!c.size())
	{
		if(!a.size())
		{
			puts("0");
			return 0;	
		}	
		++cnt;
		srand(time(0));
		while(1)
		{
			y[cnt]=0;
			for(int i=1;i<=6;++i)
				y[cnt]=y[cnt]*37+rand()%26+11;
			if(s.find(y[cnt]) == s.end())break;
		}
		int u=a.front();a.pop();
		s.erase(dy[u]);
		x[cnt]=dy[u];
		dy[u]=y[cnt];
		s.insert(dy[u]);
		c.push(dw[u]);
		dw[u]=-1;
		a.push(u);
	}
/*	cerr<<a.size()<<endl;
	cerr<<b.size()<<endl;
	cerr<<c.size()<<endl;*/
	while(c.size() && cnt<=n*2)
	{
		int u=c.front(),v;c.pop();
		++cnt;
		y[cnt]=dd[u];
		if(u<=ta)
		{
			if(!a.size())
			{
				puts("failed");
				return 0;
			}
			v=a.front(),a.pop();
		}
		else
		{
			if(!b.size())
			{
				puts("failed");
				return 0;
			}
			v=b.front(),b.pop();
		}
		x[cnt]=dy[v];
		if(~dw[v])
			c.push(dw[v]);
	}
	printf("%I64d\n",cnt);
	for(int i=1;i<=cnt;++i)
		printf("move "),pri(x[i]),pri(y[i]),putchar('\n');
}