#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> mp;
vector<int> v,v1;

int a[200010],b[200010],fa[200010],to[200010],size[200010],pre[200010],n,m,s,tt;
bool bo[200010],vis[200010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(int x)
{
	static char s[233];
	if (!x) { putchar('0');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
}

inline int find(int x) { return (x==fa[x])?x:fa[x]=find(fa[x]); }

inline void merge(int x,int y)
{
	int f1=find(x),f2=find(y);
	if (f1!=f2) fa[f1]=f2,size[f2]+=size[f1];
}

int main()
{
	n=rd();s=rd();
	for (int i=1;i<=n;i++) a[i]=b[i]=rd();
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++) if (a[i]!=b[i]) bo[i]=true;
	for (int i=1;i<=n;i++) fa[i]=i,size[i]=1;
	m=0;
	for (int i=1;i<=n;i++) if (bo[i]&&!mp[b[i]]) mp[b[i]]=i;
	for (int i=1;i<=n;i++) if (a[i]==b[i]) to[i]=i;
	tt=0;
	for (int i=1;i<=n;i++) if (a[i]!=b[i])
	{
		to[i]=mp[a[i]];tt++;
		mp[a[i]]++;
		while (!bo[mp[a[i]]]&&b[mp[a[i]]]==a[i]) mp[a[i]]++;
	}
	for (int i=1;i<=n;i++) if (a[i]!=b[i]&&!vis[i])
	{
		m++;
		for (int j=i;!vis[j];j=to[j]) merge(i,j),vis[j]=true;
	}
	memset(vis,false,sizeof(vis));
	mp.clear();
	for (int i=1;i<=n;i++) if (a[i]!=b[i]) pre[i]=mp[a[i]],mp[a[i]]=i;
	for (int i=n;i;i--) if (a[i]!=b[i]&&!vis[i]) for (int j=i;j;j=pre[j]) if (a[j]!=b[j])
	{
		vis[j]=true;
		if (find(j)!=find(i)) swap(to[j],to[i]),merge(i,j),m--;
	}
	if (!m) { puts("0");return 0; }
	if (tt>s) { puts("-1");return 0; }
	if (m==1||s-tt<=2)
	{
		printf("%d\n",m);
		memset(vis,false,sizeof(vis));
		for (int i=1;i<=n;i++) if (a[i]!=b[i]&&!vis[i])
		{
			print(size[find(i)]);putchar('\n');
			for (int j=i;!vis[j];j=to[j]) print(j),putchar(' '),vis[j]=true;
			putchar('\n');
		}
		return 0;
	}
	s=min(s,tt+m);
	int hh=s-tt;
	memset(vis,false,sizeof(vis));
	printf("%d\n",m-hh+2);
	int now=0;
	for (int i=1;i<=n;i++) if (a[i]!=b[i]&&!vis[i])
	{
		now++;v1.push_back(i);
		for (int j=i;!vis[j];j=to[j]) v.push_back(j),vis[j]=true;
		if (now==hh) break;
	}
	printf("%d\n",v.size());
	for (int i=0;i<v.size();i++) print(v[i]),putchar(' ');
	putchar('\n');
	printf("%d\n",v1.size());
	reverse(v1.begin(),v1.end());
	for (int i=0;i<v1.size();i++) print(v1[i]),putchar(' ');
	putchar('\n');
	for (int i=1;i<=n;i++) if (a[i]!=b[i]&&!vis[i])
	{
		print(size[find(i)]);putchar('\n');
		for (int j=i;!vis[j];j=to[j]) print(j),putchar(' '),vis[j]=true;
		putchar('\n');
	}
	return 0;
}