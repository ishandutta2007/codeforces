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
int a[N>>1],l[N],r[N];
int v[N>>1],ans[N];
int head[N>>1],nex[N<<1],to[N<<1];
int cnt;
bitset<N>b;
void add(int u,int v)
{
	nex[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=m;++i)
	{
		l[i]=read();
		r[i]=read();
		--a[l[i]];
		--a[r[i]];
		add(l[i],i);
		add(r[i],i);
	}
	cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]>=0)v[++cnt]=i;
	}
	int s=0;
	for(int i=1;i<=cnt;++i)
	{
		for(int j=head[v[i]];j;j=nex[j])
		{
			int t=to[j];
			if(!b[t])
			{
				ans[++s]=t;
				b[t]=1;
			}
			t=(l[t]==v[i]?r:l)[t];
			if(!++a[t])v[++cnt]=t;
		}
	}
	if(s!=m)
	{
		puts("DEAD");
		return 0;
	}
	puts("ALIVE");
	for(int i=m;i>=1;--i)write(ans[i],' ');
}