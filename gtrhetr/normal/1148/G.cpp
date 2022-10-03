#include<bits/stdc++.h>
using namespace std;

vector<int> v[100010],g[100010];

int a[100010],a1[100010],a2[100010],ans[100010];
int p[10000010],miu[10000010],mn[10000010],sum[10000010],d[10000010],tot;
int num[100010],h[100010],c[110],n,k,tt,cnt;
bool bo[10000010],vis[100010];

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

inline void pre_gao()
{
	miu[1]=1;tot=0;
	for (int i=2;i<=10000000;i++)
	{
		if (!bo[i]) p[++tot]=i,miu[i]=-1,mn[i]=i;
		for (int j=1;j<=tot&&i*p[j]<=10000000;j++)
		{
			bo[i*p[j]]=true;mn[i*p[j]]=p[j];
			if (i%p[j]==0) { miu[i*p[j]]=0;break; }
			miu[i*p[j]]=-miu[i];
		}
	}
}

inline int dfs(int x,int y)
{
	if (x>cnt) return sum[y];
	return dfs(x+1,y)+dfs(x+1,y*c[x]);
}

inline void dfs1(int x,int y,int id)
{
	if (x>cnt) { sum[y]+=miu[y];v[id].push_back(y);return; }
	dfs1(x+1,y,id);dfs1(x+1,y*c[x],id);
}

inline void dfs2(int x,int y,int id)
{
	if (x>cnt) { v[id].push_back(y);return; }
	dfs2(x+1,y,id);dfs2(x+1,y*c[x],id);
}

inline bool cmp(const int &x,const int &y) { return g[x].size()>g[y].size(); }

inline void gao(int l,int r,int ql,int qr)
{
	if (ql>qr) return;
	if (l==r)
	{
		for (int i=ql;i<=qr;i++) g[h[l]].push_back(a[i]);
		return;
	}
	int mid=(l+r)>>1;
	for (int i=l;i<=mid;i++) for (int t:v[h[i]]) sum[t]+=miu[t];
	int t1=0,t2=0;
	for (int i=ql;i<=qr;i++)
	{
		int now=0;
		for (int t:v[a[i]]) now+=sum[t];
		if (now) a1[++t1]=a[i];
		else a2[++t2]=a[i];
	}
	for (int i=l;i<=mid;i++) for (int t:v[h[i]]) sum[t]=0;
	for (int i=1;i<=t1;i++) a[ql+i-1]=a1[i];
	for (int i=1;i<=t2;i++) a[ql+t1+i-1]=a2[i];
	gao(l,mid,ql,ql+t1-1);gao(mid+1,r,ql+t1,qr);
}

int main()
{
	n=rd();k=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	pre_gao();
	tt=0;
	for (int i=1;i<=n;i++)
	{
		int now=num[i];cnt=0;
		for (;now>1;now/=mn[now])
		{
			if (!d[mn[now]]) c[++cnt]=mn[now];
			d[mn[now]]++;
		}
		int hh=dfs(1,1);
		if (!hh) h[++tt]=i,vis[i]=true,dfs1(1,1,i);
		else dfs2(1,1,i);
		now=num[i];
		for (;now>1;now/=mn[now]) d[mn[now]]=0;
	}
	if (k<=tt)
	{
		for (int i=1;i<=k;i++) print(h[i]);
		putchar('\n');
		return 0;
	}
	tot=0;
	for (int i=1;i<=n;i++) if (!vis[i]) a[++tot]=i;
	memset(sum,0,sizeof(sum));
	gao(1,tt,1,tot);
	sort(h+1,h+tt+1,cmp);
	bool flag=false;tot=0;
	for (int i=1;i<=tt;i++)
	{
		if (!k) break;
		if (k==1) flag=true,k++;
		for (int j=0;j<k-1&&j<g[h[i]].size();j++) ans[++tot]=g[h[i]][j];
		if (g[h[i]].size()==0) puts("!!!");
		ans[++tot]=h[i];
		k-=min(k,(int)g[h[i]].size()+1);
	}
	if (!flag) for (int i=1;i<=tot;i++) print(ans[i]);
	else for (int i=2;i<=tot;i++) print(ans[i]);
	putchar('\n');
	return 0;
}