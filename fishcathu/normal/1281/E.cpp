#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<string,int> pii;
const int N=2E5+10;
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
int head[N],nex[N<<1],to[N<<1],val[N<<1],cnt;
int n,size[N];
ll a1,a2;
bitset<N>b;
void add(int u,int v,int w)
{
	nex[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	val[cnt]=w;
}
void dfs(int x,int f)
{
	size[x]=1;
	b[x]=0;
	for(int i=head[x];i;i=nex[i])
	{
		int t=to[i];
		if(t==f)continue;
		dfs(t,x);
		a2+=val[i]*1LL*min(size[t],n-size[t]);
		size[x]+=size[t];
		if(b[t])continue;
		a1+=val[i];
		b[x]=!b[x];
	}
}
void solve()
{
	n=read()<<1;
	memset(head+1,0,n<<2);
	cnt=0;
	for(int i=n;--i;)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w); 
	}
	a1=a2=0;
	dfs(1,0);
	write(a1,' ');
	write(a2,'\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}