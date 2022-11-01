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
const int N=2E5+10;
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
int head[N],nex[N],to[N],cnt;
int l[N],m[N],r[N];
const int p=998244353;
void add(int u,int v)
{
	nex[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
void dfs(int x)
{
	(to[head[x]]?l:r)[x]=1;
	for(int i=head[x];i;i=nex[i])
	{
		int t=to[i];
		dfs(t);
		r[x]=(r[x]*1ll*(l[t]+m[t])+m[x]*1ll*m[t])%p;
		m[x]=(m[x]*1ll*l[t]+l[x]*1ll*m[t])%p;
		l[x]=l[x]*1ll*l[t]%p;
	}
	l[x]=(l[x]+r[x])%p;
	m[x]=(m[x]+r[x])%p;
}
int main()
{
	int n=read();
	for(int i=2;i<=n;++i)add(read(),i);
	dfs(1);
	write(l[1],'\n');
}