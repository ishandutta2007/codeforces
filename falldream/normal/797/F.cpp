#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define pa pair<ll,int>
#define mp(x,y) make_pair(x,y)
#define ll long long
#define MN 5000
#define INF 200000000000000000LL
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x * f;
}

int n,m,x[MN+5];
ll f[2][MN+5],s[MN+5][MN+5];
struct hole
{	
	int x,c;
	bool operator<(const hole&b)const{return x<b.x;}
}y[MN+5];
struct MyQueue
{
	int top,tail;pa q[MN+5];
	void clear(){q[top=tail=0]=mp(0,0);}
	void push(ll x,int pos)
	{
		while(top>=tail&&x<=q[top].first) --top;
		q[++top]=mp(x,pos);
	}
	ll get(int pos)
	{
		while(top>=tail&&q[tail].second<pos) ++tail;
		if(top<tail) return INF;
		return q[tail].first;
	}
}q;

inline int abs(int x){return x<0?-x:x;}

int main()
{
	memset(f,127,sizeof(f));
	n=read();m=read();
	for(int i=1;i<=n;i++) x[i]=read();
	for(int i=1;i<=m;i++) y[i].x=read(),y[i].c=read();
	sort(x+1,x+n+1);sort(y+1,y+m+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			s[i][j]=s[i-1][j]+abs(x[i]-y[j].x);
	f[0][0]=0;
	for(int j=1,now=1,pre=0;j<=m;j++)
	{
		q.clear();
		for(int i=1;i<=n;i++)
		{
			f[now][i]=q.get(i-y[j].c)+s[i][j];
	//		cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
			q.push(f[pre][i]-s[i][j],i);
			f[now][i]=min(f[now][i],f[pre][i]);
		}
		now^=1;pre^=1;memset(f[now],127,sizeof(f[now]));
	}
	printf("%lld\n",f[m&1][n]<INF?f[m&1][n]:-1);
	return 0;
}