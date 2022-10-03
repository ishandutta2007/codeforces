#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

bitset<2010> a[2010];

queue<pii> q;
pii ans[2010];

int cnt[2010],t,n,m,tt;
bool vis[2010],bo[2010];
char s[2010];

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
	if (!x) { putchar('0');putchar(' ');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar(' ');
}

int main()
{
	t=rd();
	while (t--)
	{
		n=rd();m=rd();
		for (int i=1;i<=n;i++) a[i].reset();
		for (int i=1;i<=m;i++)
		{
			scanf("%s",s+1);cnt[i]=0;
			for (int j=1;j<=n;j++) if (s[j]=='1') a[j][i]=true,cnt[i]++;
		}
		memset(vis,false,sizeof(vis));
		memset(bo,false,sizeof(bo));
		while (!q.empty()) q.pop();
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (i!=j&&(a[i]&a[j])==a[i]) q.push(pii(i,j));
		bool flag=true;
		for (int hhh=1;hhh<n;hhh++)
		{
			for (int j=1;j<=m;j++) if (!bo[j]&&cnt[j]<=1)
			{
				bo[j]=true;
				for (int i=1;i<=n;i++) if (a[i][j])
				{
					a[i][j]=0;
					if (vis[i]) continue;
					for (int j=1;j<=n;j++) if (j!=i&&!vis[j]&&(a[i]&a[j])==a[i]) q.push(pii(i,j));
				}
			}
			int h1=0,h2=0;
			while (!q.empty())
			{
				pii hh=q.front();q.pop();
				if (vis[hh.first]||vis[hh.second]) continue;
				h1=hh.first;h2=hh.second;break;
			}
			if (!h1) { flag=false;break; }
			ans[hhh]=pii(h1,h2);vis[h1]=true;
			for (int i=1;i<=m;i++) if (a[h1][i]) cnt[i]--;
		}
		if (!flag) { puts("NO");continue; }
		puts("YES");
		for (int i=1;i<n;i++) print(ans[i].first),print(ans[i].second),putchar('\n');
	}
	return 0;
}