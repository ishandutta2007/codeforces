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
const int N=5E5+10;
const int inf=1<<30;
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
int head[N],nex[N<<1],to[N<<1],cnt;
int q[N],l[N],r[N];
bitset<N>b;
void add(int u,int v)
{
	nex[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
int main()
{
	int n=read();
	for(int i=n;--i;)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	l[1]=q[1]=b[1]=cnt=1;
	for(int s=1;s;)
	{
		int x=q[s--];
		for(int i=head[x];i;i=nex[i])
		{
			int t=to[i];
			if(b[t])continue;
			b[t]=1;
			q[++s]=t;
			l[t]=++cnt;
		}
		r[x]=++cnt;
	}
	for(int i=1;i<=n;++i)
	{
		write(l[i],' ');
		write(r[i],'\n');
	}
}