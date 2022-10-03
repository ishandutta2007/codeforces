#include<bits/stdc++.h>
using namespace std;

struct node { int t,next; }a[200010],a1[200010];

vector<int> v[200010];
queue<int> q;

int head[200010],head1[200010],num[200010],out[200010],f[200010],sum[200010],n,m,tot,tot1;
bool vis[200010];

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

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }
inline void add1(int x,int y) { a1[++tot1].t=y;a1[tot1].next=head1[x];head1[x]=tot1; }

int main()
{
	n=rd();m=rd();tot=tot1=0;
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<=m;i++) { int x=rd(),y=rd();add(x,y);add1(y,x);out[x]++; }
	for (int i=1;i<=n;i++) if (!out[i]) q.push(i);
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=head[x];i;i=a[i].next) vis[f[a[i].t]]=true;
		for (int i=0;i<=n;i++) if (!vis[i]) { f[x]=i;break; }
		for (int i=head[x];i;i=a[i].next) vis[f[a[i].t]]=false;
		v[f[x]].push_back(x);sum[f[x]]^=num[x];
		for (int i=head1[x];i;i=a1[i].next)
		{
			int t=a1[i].t;
			if (!(--out[t])) q.push(t);
		}
	}
	for (int i=n;~i;i--) if (sum[i])
	{
		puts("WIN");
		for (int x:v[i]) if (num[x]>=(sum[i]^num[x]))
		{
			num[x]=sum[i]^num[x];
			for (int j=head[x];j;j=a[j].next)
			{
				int t=a[j].t;
				if (vis[f[t]]) continue;
				vis[f[t]]=true;
				num[t]=sum[f[t]]^num[t];
			}
			break;
		}
		for (int j=1;j<=n;j++) print(num[j]);
		putchar('\n');
		return 0;
	}
	puts("LOSE");
	return 0;
}