#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1E5+10;
ll read()
{
	ll a=0;
	char b=1,c;
	do if((c=getchar())==45)b=-1;while(c<48||c>57);
	do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
	return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int head[N],nex[N<<2],to[N<<2],val[N<<2];
int cnt,dis[N],mn[N],q[N],f[N],s;
void pop()
{
	int x=q[s--],i=1;
	while(ls<=s)
	{
		int t=ls==s||dis[q[ls]]<dis[q[rs]]?ls:rs;
		if(dis[q[t]]>=dis[x])break;
		f[q[i]=q[t]]=i;
		i=t;
	}
	f[q[i]=x]=i;
}
void push(int x,int val)
{
	dis[x]=val;
	int i=f[x]?f[x]:++s;
	while(i&&val<dis[q[i>>1]])
	{
		f[q[i]=q[i>>1]]=i;
		i>>=1;
	}
	f[q[i]=x]=i;
}
void add(int u,int v,int w)
{
	nex[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	val[cnt]=w;
}
int main()
{
	int n=read();
	for(int m=read();m--;)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	memset(dis+2,127,n-1<<2);
	memset(mn+1,127,n<<2);
	for(q[1]=f[1]=s=1;s;)
	{
		int x=q[1];
		pop();
		for(int i=head[x];i;i=nex[i])
		{
			int y=to[i],l=val[i];
			if(l>=mn[y])continue;
			mn[y]=l;
			for(int j=head[y];j;j=nex[j])
			{
				int t=to[j],s=l+val[j];
				s=dis[x]+s*s;
				if(s<dis[t])push(t,s);
			}
		}
	}
	const int inf=2139062143;
	for(int i=1;i<=n;++i)write(dis[i]==inf?-1:dis[i],' ');
}