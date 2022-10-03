#include<bits/stdc++.h>
using namespace std;

vector<int> v[500010];

stack<int> st;

int d[500010],h[500010],fa[500010],from[500010],id[500010],dep[500010],t,n,m,tt,cnt;
bool bo[500010],vis[500010];

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

inline void output()
{
	int tt=0;
	for (int i=1;i<=n;i++) if (!bo[i]) tt++;
	if (!tt||tt==n) { puts("No");return; }
	puts("Yes");
	print(tt);putchar('\n');
	for (int i=1;i<=n;i++) if (!bo[i]) print(i);
	putchar('\n');
}

inline bool dfs1(int x,int rt)
{
	st.push(x);vis[x]=true;
	if (d[x]%3==1&&x!=rt) return true;
	for (int t:v[x]) if (!vis[t]&&dfs1(t,rt)) return true;
	st.pop();return false;
}

inline bool dfs2(int x)
{
	vis[x]=true;from[x]=cnt;
	int res=0;
	for (int t:v[x]) if (d[t]%3==2&&vis[t]&&t!=fa[x])
	{
		if (dep[t]>dep[res]) res=t;
	}
	if (res)
	{
		for (int i=x;i!=res;i=fa[i]) h[++tt]=i;
		h[++tt]=res;
		return true;
	}
	for (int t:v[x]) if (d[t]%3==2&&!vis[t])
	{
		fa[t]=x;dep[t]=dep[x]+1;
		if (dfs2(t)) return true;
	}
	return false;
}

inline void gao(int x,int y)
{
	while (x!=y)
	{
		if (dep[x]>dep[y]) bo[x]=true,x=fa[x];
		else bo[y]=true,y=fa[y];
	}
	bo[x]=true;
}

inline bool cmp(const int &x,const int &y) { return d[x]%3<d[y]%3; }
inline bool cmp1(const int &x,const int &y) { return dep[x]<dep[y]; }

inline void work(int cas)
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) v[i].clear(),d[i]=bo[i]=0;
	for (int i=1;i<=m;i++)
	{
		int x=rd(),y=rd();
		d[x]++;d[y]++;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if (n==1) { puts("No");return; }
	int res=0;
	for (int i=1;i<=n;i++) if (d[i]%3==0) res=i;
	if (res) { bo[res]=true;output();return; }
	int s=0;
	for (int i=1;i<=n;i++) if (d[i]%3==1) s++;
	for (int i=1;i<=n;i++) sort(v[i].begin(),v[i].end(),cmp);
	for (int i=1;i<=n;i++) vis[i]=false,fa[i]=from[i]=dep[i]=0;
	cnt=0;
	for (int i=1;i<=n;i++) if (d[i]%3==2&&!vis[i])
	{
		tt=0;cnt++;dep[i]=1;
		if (!dfs2(i)) continue;
		for (int j=1;j<=tt;j++) bo[h[j]]=true;
		output();
		return;
	}
	if (s>1)
	{
		for (int i=1;i<=n;i++) vis[i]=false;
		while (!st.empty()) st.pop();
		for (int i=1;i<=n;i++) if (d[i]%3==1) { dfs1(i,i);break; }
		tt=0;
		while (!st.empty()) h[++tt]=st.top(),st.pop();
		reverse(h+1,h+tt+1);
		int id=2;
		for (int i=2;i<tt;i++) for (int t:v[h[i]]) if (t==h[1]) id=i;
		bo[h[1]]=true;
		for (int i=id;i<=tt;i++) bo[h[i]]=true;
		output();
		return;
	}
	for (int i=1;i<=cnt;i++) id[i]=0;
	res=0;
	for (int i=1;i<=n;i++) if (d[i]%3==1) res=i;
	int tot=0;bo[res]=true;
	sort(v[res].begin(),v[res].end(),cmp1);
	for (int t:v[res])
	{
		if (!id[from[t]]) id[from[t]]=t;
		else if (id[from[t]]!=-1)
		{
			tot++;
			gao(id[from[t]],t);
			id[from[t]]=-1;
			if (tot==2) break;
		}
	}
	output();
}

int main()
{
	t=rd();
	for (int i=1;i<=t;i++) work(i);
	return 0;
}