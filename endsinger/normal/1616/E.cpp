#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],b[N],bt[N],d[N];
char s[N],t[N];
set<int>p[30];
long long ans,r,z;
void add(int x,int v)
{
	for(int i=x;i>0;i-=i&(-i))
		bt[i]+=v;
}
int ask(int x)
{
	int v=0;
	for(int i=x;i<=n;i+=i&(-i))
		v+=bt[i];
	return v;
}
void sol()
{
	scanf("%d%s%s",&n,s+1,t+1);
	for(int i=0;i<26;i++)
		p[i].clear();
	for(int i=1;i<=n;i++)
	{
		a[i]=s[i]-'a';
		p[a[i]].insert(i);
		b[i]=t[i]-'a';
		d[i]=0;
	}
	for(int i=0;i<=n;i++)
		bt[i]=0;
	ans=1ll*n*n+100,r=0,z=1;
	for(int i=1;i<=n;i++)
	{
		while(d[z])
			z++;
		if(a[z]<b[i])
		{
			ans=min(ans,r);
			break;
		}
		int mn=n+1;
		for(int j=0;j<b[i];j++)
			if(p[j].size())
				mn=min(mn,*p[j].begin());
		if(mn<=n)
			ans=min(ans,r+mn+ask(mn)-i);
		if(p[b[i]].size())
		{
			int x=*p[b[i]].begin();
			d[x]=1;
			r+=x-i+ask(x);
			add(x,1);
			p[b[i]].erase(x);
		}
		else
			break;
	}
	if(ans>1ll*n*n)
		ans=-1;
	printf("%lld\n",ans);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}