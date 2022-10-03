#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define inf 10000000000000LL

struct node { int t,v,next; }a[500010];

vector<int> v[250010];
vector<pii> g[250010];

ll f[250010][2],ans[250010];
int head[250010],d[250010],h[250010],rt[250010],n,tt,tot;
bool bo[250010],vis[250010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(ll x)
{
	static char s[233];
	if (!x) { putchar('0');putchar(' ');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar(' ');
}

inline void add(int x,int y,int z) { a[++tot].t=y;a[tot].v=z;a[tot].next=head[x];head[x]=tot; }

ll sum[5000010];
int ch[5000010][2],num[5000010],size[5000010];

inline int newnode(int x)
{
	int now=++tot;
	num[now]=sum[now]=x;size[now]=1;
	return now;
}

inline void pushup(int o)
{
	size[o]=size[ch[o][0]]+size[ch[o][1]]+1;
	sum[o]=sum[ch[o][0]]+sum[ch[o][1]]+num[o];
}

inline pii split(int x,int k)
{
	if (!x) return pii(0,0);
	if (!k) return pii(0,x);
	if (k==size[x]) return pii(x,0);
	if (k<=size[ch[x][0]]) { pii hh=split(ch[x][0],k);ch[x][0]=hh.second;hh.second=x;pushup(x);return hh; }
	else { pii hh=split(ch[x][1],k-size[ch[x][0]]-1);ch[x][1]=hh.first;hh.first=x;pushup(x);return hh; }
}

inline pii split1(int x,int y)
{
	if (!x) return pii(0,0);
	if (y<=num[x]) { pii hh=split1(ch[x][0],y);ch[x][0]=hh.second;hh.second=x;pushup(x);return hh; }
	else { pii hh=split1(ch[x][1],y);ch[x][1]=hh.first;hh.first=x;pushup(x);return hh; }
}

inline int merge(int x,int y)
{
	if (!x||!y) return x|y;
	if ((ll)rand()*rand()%(size[x]+size[y])<size[x]) { ch[x][1]=merge(ch[x][1],y);pushup(x);return x; }
	else { ch[y][0]=merge(x,ch[y][0]);pushup(y);return y; }
}

inline int insert(int o,int x)
{
	int now=newnode(x);
	pii hh=split1(o,x);
	return merge(merge(hh.first,now),hh.second);
}

inline int del(int o,int x)
{
	pii h1=split1(o,x),h2=split(h1.second,1);
	return merge(h1.first,h2.second);
}

inline ll query(int &o,int k)
{
	if (k<=0) return 0;
	if (k>size[o]) return inf;
	pii hh=split(o,k);
	ll res=sum[hh.first];
	o=merge(hh.first,hh.second);
	return res;
}

inline void dfs(int x,int y,int z,int now)
{
	vector<int> v;
	f[x][0]=f[x][1]=inf;vis[x]=true;
	ll res=0;int tt=0;
	for (int i=0;i<g[x].size();i++)
	{
		int t=g[x][i].first;
		if (t==y) continue;
		dfs(t,x,g[x][i].second,now);
		res+=f[t][1];tt++;
		v.push_back(f[t][0]-f[t][1]);
	}
	sort(v.begin(),v.end());
	f[x][0]=min(f[x][0],res+query(rt[x],d[x]-tt-now));
	f[x][1]=min(f[x][1],res+query(rt[x],d[x]-tt-1-now));
	for (int i=0;i<v.size();i++)
	{
		tt--;res+=v[i];
		f[x][0]=min(f[x][0],res+query(rt[x],d[x]-tt-now));
		f[x][1]=min(f[x][1],res+query(rt[x],d[x]-tt-1-now));
	}
	f[x][1]+=z;
}

int main()
{
	srand(19260816);
	n=rd();tot=0;
	for (int i=1;i<n;i++)
	{
		int x=rd(),y=rd(),z=rd();
		add(x,y,z);add(y,x,z);
		d[x]++;d[y]++;
	}
	for (int i=1;i<=n;i++) v[d[i]].push_back(i);
	tot=0;
	for (int i=1;i<=n;i++) for (int j=head[i];j;j=a[j].next) rt[i]=insert(rt[i],a[j].v);
	tt=0;
	for (int i=n-1;~i;i--)
	{
		for (int j=0;j<v[i+1].size();j++)
		{
			int x=v[i+1][j];
			h[++tt]=x;bo[x]=true;
			for (int k=head[x];k;k=a[k].next)
			{
				int t=a[k].t;
				if (bo[t])
				{
					g[x].push_back(pii(t,a[k].v));
					g[t].push_back(pii(x,a[k].v));
					rt[x]=del(rt[x],a[k].v);
					rt[t]=del(rt[t],a[k].v);
				}
			}
		}
		ll res=0;
		for (int j=1;j<=tt;j++) if (!vis[h[j]]) dfs(h[j],0,0,i),res+=f[h[j]][0];
		ans[i]=res;
		for (int j=1;j<=tt;j++) vis[h[j]]=false;
	}
	for (int i=0;i<n;i++) print(ans[i]);
	putchar('\n');
	return 0;
}