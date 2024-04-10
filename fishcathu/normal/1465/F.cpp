#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1E6+10;
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
int fa[N],a[N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int getans(int n)
{
	int ans=1,p=1E9+7;
	while(n%3)n-=2,ans<<=1;
	n/=3;
	for(int i=3;n;n>>=1,i=i*1ll*i%p)if(n&1)ans=ans*1ll*i%p;
	return ans;
}
int work(int &l,int &r)
{
	int t=min(l,r);
	l-=t;
	r-=t;
	return t;
}
int getans(int b,int c,int d)
{
	int s=b+c*2+d*4;
	if(s%3==2)return getans(b,c-1,d);
	if(s%3==1)
	{
		if(s==1)return 1;
		return min(getans(b,c-2,d),getans(b,c,d-1));
	}
	int ans=0;
	while(c<0)
	{
		if(b>=2)b-=2,++ans,++c;
		else --d,++ans,c+=2;
	}
	if(d<0)
	{
		while(c<2)
		{
			b-=2,++ans,++c;
		}
		c-=2,++ans,++d;
	}
	ans+=work(b,c);
	ans+=work(c,d)<<1;
	if(c)ans+=c;
	else ans+=(2*b+5*d)/3;
	return ans;
}
int main()
{
	for(int x=read();x--;)
	{
		int n=read(),ans=0,b=0,c=0,d=0;
		for(int i=1;i<=n;++i)fa[i]=i,a[i]=0;
		for(int i=1;i<=n;++i)fa[find(i)]=find(read());
		for(int i=1;i<=n;++i)++a[find(i)];
		for(int i=1;i<=n;++i)if(a[i])
		{
			if(a[i]%3==0)
			{
				ans+=(a[i]-3)/3;
			}
			else if(a[i]%3==1)
			{
				if(a[i]==1)++b;
				else
				{
					ans+=(a[i]-4)/3;
					++d;
				}
			}
			else
			{
				ans+=(a[i]-2)/3;
				++c;
			}
		}
		printf("%d %d\n",getans(n),ans+getans(b,c,d));
	}
}