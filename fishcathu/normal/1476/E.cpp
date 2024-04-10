#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1E5+1;
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
char a[5],b[5];
int head[N],nex[N*15],to[N*15];
int in[N],cnt,ans[N],mp[531441],x;
void add(int u,int v)
{
	nex[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
int f()
{
	int res=0;
	for(int i=0,j=1;i<x;++i,j*=27)
	{
		int t=a[i]=='_'?0:a[i]-96;
		res+=t*j;
	}
	return res;
}
int main()
{
	int n=read(),m=read();
	x=read();
	for(int i=1;i<=n;++i)
	{
		scanf("%s",a);
		mp[f()]=i;
	}
	while(m--)
	{
		scanf("%s",b);
		int c=read();
		bool bo=0;
		for(int i=1<<x;i--;)
		{
			for(int j=0;j<x;++j)
			{
				a[j]=1<<j&i?'_':b[j];
			}
			int z=mp[f()];
			if(!z)continue;
			if(z==c)bo=1;
			else
			{
				add(c,z);
				++in[z];
			}
		}
		if(!bo)
		{
			puts("NO");
			return 0;
		}
	}
	cnt=0;
	for(int i=1;i<=n;++i)if(!in[i])ans[++cnt]=i;
	for(int i=1;i<=cnt;++i)
	{
		for(int j=head[ans[i]];j;j=nex[j])
		{
			int t=to[j];
			--in[t];
			if(!in[t])ans[++cnt]=t;
		}
	}
	if(cnt!=n)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(int i=1;i<=n;++i)write(ans[i],' ');
	putchar('\n');
}