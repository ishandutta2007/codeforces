#include<bits/stdc++.h>
using namespace std;

vector<int> v[1600010];
stack<int> st;

int dfn[1600010],low[1600010],from[1600010],n,m,m1,m2,cl,cnt;
bool inq[1600010],bo[800010];

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

inline int calc(const int &x,const int &y) { return (x-1)*2+y+1; }

inline void dfs(int x)
{
	dfn[x]=low[x]=++cl;st.push(x);inq[x]=true;
	for (int t:v[x])
	{
		if (!dfn[t]) dfs(t),low[x]=min(low[x],low[t]);
		else if (inq[t]) low[x]=min(low[x],dfn[t]);
	}
	if (dfn[x]==low[x])
	{
		cnt++;
		while (233)
		{
			int hh=st.top();st.pop();
			from[hh]=cnt;inq[hh]=false;
			if (hh==x) break;
		}
	}
}

int main()
{
	m1=rd();n=rd();m=rd();m2=rd();
	for (int i=1;i<=m1;i++)
	{
		int x=rd(),y=rd();
		v[calc(x,0)].push_back(calc(y,1));
		v[calc(y,0)].push_back(calc(x,1));
	}
	for (int i=1;i<=n;i++)
	{
		int l=rd(),r=rd();
		v[calc(i,1)].push_back(calc(l+n,1));
		v[calc(l+n,0)].push_back(calc(i,0));
		if (r<m)
		{
			v[calc(i,1)].push_back(calc(r+1+n,0));
			v[calc(r+1+n,1)].push_back(calc(i,0));
		}
	}
	for (int i=1;i<=m2;i++)
	{
		int x=rd(),y=rd();
		v[calc(x,1)].push_back(calc(y,0));
		v[calc(y,1)].push_back(calc(x,0));
	}
	for (int i=1;i<m;i++) v[calc(n+i,0)].push_back(calc(n+i+1,0));
	for (int i=m;i>1;i--) v[calc(n+i,1)].push_back(calc(n+i-1,1));
	for (int i=1;i<=(n+m)*2;i++) if (!dfn[i]) dfs(i);
	bool flag=true;
	for (int i=1;i<=n+m;i++) if (from[calc(i,0)]==from[calc(i,1)]) flag=false;
	if (!flag) { puts("-1");return 0; }
	for (int i=1;i<=n+m;i++) bo[i]=(from[calc(i,0)]<from[calc(i,1)])?0:1;
	int tt=0;
	for (int i=1;i<=n;i++) if (bo[i]) tt++;
	print(tt);
	flag=false;
	for (int i=m;i;i--) if (bo[n+i]) { print(i);flag=true;break; }
	if (!flag) print(1);
	putchar('\n');
	for (int i=1;i<=n;i++) if (bo[i]) print(i);
	putchar('\n');
	return 0;
}