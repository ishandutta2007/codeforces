







































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[100005],fl,tans[100005],f[100005],c[100005],g[100005];
int st[100005],tp;
char s[15];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%s",s);
	m=strlen(s);
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d",a[i]);
			if(i<n) printf("%c",s[0]);
		}
		return 0;
	}
	for(int i=0;i<m;i++)
	{
		if(s[i]=='+') fl|=1;
		if(s[i]=='-') fl|=2;
		if(s[i]=='*') fl|=4;
	}
	if(fl==3)
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d",a[i]);
			if(i<n) printf("+");
		}
		return 0;
	}
	if(fl==6)
	{
		int id=n+1;
		for(int i=1;i<=n;i++)
			if(!a[i])
			{
				id=i;
				break;
			}
		for(int i=1;i<=n;i++)
		{
			printf("%d",a[i]);
			if(i<n)
			{
				if(i+1!=id) printf("*");
				else printf("-");
			}
		}
		return 0;
	}
	for(int l=1,r;l<=n;l=r+1)
	{
		r=l;
		if(a[l]==0) continue;
		while(r<n&&a[r+1]) r++;
		int nw=1,fl=0;
		for(int i=l;i<=r;i++)
		{
			if(1ll*nw*a[i]>1e9)
			{
				fl=1;
				break;
			}
			nw*=a[i];
			c[i]=nw;
		}
		c[l-1]=1;
		if(fl==1)
		{
			int ll=l,rr=r;
			while(ll<=r&&a[ll]==1) ll++;
			while(rr>=l&&a[rr]==1) rr--;
			for(int i=ll;i<rr;i++)
				tans[i]=1;
			continue;
		}
		tp=1;
		st[tp]=l-1;
		f[l-1]=0;
		for(int i=l;i<=r;i++)
		{
			f[i]=f[i-1]+a[i];
			g[i]=i-1;
			for(int j=1;j<=tp;j++)
			{
				int q=f[st[j]]+c[i]/c[st[j]];
				if(q>f[i])
				{
					f[i]=q;
					g[i]=st[j];
				}
			}
			if(a[i]>1) st[++tp]=i-1;
		}
		int u=r;
		while(u>=l)
		{
			int v=g[u];
			for(int i=v+1;i<u;i++)
				tans[i]=1;
			u=v;
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d",a[i]);
		if(i<n) printf("%c",tans[i]?'*':'+');
	}
	return 0;
}