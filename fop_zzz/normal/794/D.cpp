#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e9
#define int ll
#define pb push_back
#define local freopen("in.in","r",stdin);
#define c(x,y)  ((x-1))*m+(y)
using namespace std;
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read()
{
	ll t=0,f=1;char c=gc();
	while(!isdigit(c))  {if(c=='-') f=-1;c=gc();}
	while(isdigit(c))   t=t*10+c-'0',c=gc();
	return t*f;
}
inline void write(ll x){if(x<0) {putchar('-');write(-x);return;}if(x>=10)    write(x/10);putchar(x%10+'0');}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

const int N=650001;
int n,m,in[N],poi[N],nxt[N],head[N],dis[N],cnt[N],t,mx,st;
inline void add(int x,int y)
{
	poi[++t]=y;nxt[t]=head[x];head[x]=t;in[x]++;
	poi[++t]=x;nxt[t]=head[y];head[y]=t;in[y]++;
}
inline void Bfs(int St)
{
	bool ned=0;
	if(!st)	ned=1;
	
	queue<int> Q;
	memset(dis,0,sizeof dis);
	dis[St]=1;Q.push(St);
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();
		if(ned)st=x;
		for(int i=head[x];i;i=nxt[i])	if(!dis[poi[i]])	dis[poi[i]]=dis[x]+1,Q.push(poi[i]);
	}
	For(i,1,n)	mx=max(mx,dis[i]);
}
signed main()
{
	n=read();m=read();
	if(n<=10000)	if(n*(n-1)/2==m)
	{
		puts("YES");
		For(i,1,n)	write_p(1);
		return 0;
	}
	For(i,1,m)	add(read(),read());
	Bfs(1);
	if(mx==2)	For(i,1,n)	if(mx==dis[i]&&in[i]!=in[1])	st=i;
	
	Bfs(st);
	For(i,1,n)	if(in[i]==in[st])	if(dis[i]==2)	dis[i]=1;
	For(i,1,n)	cnt[dis[i]]++;
//	
//	cout<<st<<endl;
//	For(i,1,n)	cout<<i<<' '<<dis[i]<<' '<<in[i]<<endl;
	ll sum=0;
	For(i,1,mx)	sum+=cnt[i]*(cnt[i]-1)/2;
	For(i,1,mx-1)	sum+=cnt[i]*cnt[i+1];
	
	if(sum!=m)	{puts("NO");exit(0);}
	
	puts("YES");
	For(i,1,n)	write_p(dis[i]);
}