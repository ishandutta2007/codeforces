#include<bits/stdc++.h>
using namespace std;

struct node
{
	mutable int x,l,r;
	node() {}
	node(int x1,int l1,int r1):x(x1),l(l1),r(r1) {}
};

deque<node> q;

int f[4010],g[4010];
int val[4010][4010],sum[4010][4010],num[4010][4010],n,k;

char buf[1000010],*cur=buf+1000010;

inline char getc()
{
	(cur==buf+1000010)?fread(cur=buf,1,1000010,stdin):0;
	return *cur++;
}

inline int rd()
{
	int x=0;char ch=getc();
	for (;ch<'0'||ch>'9';ch=getc());
	for (;ch>='0'&&ch<='9';ch=getc()) x=x*10+ch-'0';
	return x;
}

inline int calc(int x,int y) { return f[x]+num[x+1][y]; }

inline bool cmp(int x,int y,int z)
{
	int h1=calc(x,z),h2=calc(y,z);
	return (h1>h2||(h1==h2&&g[x]>g[y]));
}

inline void gao(int now)
{
	while (!q.empty()) q.pop_back();
	q.push_back(node(0,0,n));
	f[0]=g[0]=0;
	for (int i=1;i<=n;i++)
	{
		q.front().l++;
		if (q.front().l>q.front().r) q.pop_front();
		f[i]=calc(q.front().x,i)+now;g[i]=g[q.front().x]+1;
		while (!q.empty()&&cmp(q.back().x,i,q.back().l)) q.pop_back();
		if (q.empty()) q.push_back(node(i,i,n));
		else
		{
			if (cmp(i,q.back().x,n)) continue;
			int l=q.back().l,r=n;
			while (l<r)
			{
				int mid=(l+r)>>1;
				if (cmp(q.back().x,i,mid)) r=mid;
				else l=mid+1;
			}
			q.back().r=l-1;
			q.push_back(node(i,l,n));
		}
	}
}

int main()
{
	n=rd();k=rd();
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) val[i][j]=rd();
	for (int i=1;i<=n;i++) for (int j=i;j;j--) sum[i][j]=sum[i][j+1]+val[i][j];
	for (int i=1;i<=n;i++) for (int j=i;j<=n;j++) num[i][j]=num[i][j-1]+sum[j][i];
	int l=0,r=num[1][n];
	while (l<r)
	{
		int mid=(l+r)>>1;
		gao(mid);
		if (g[n]<=k) r=mid;
		else l=mid+1;
	}
	gao(l);
	printf("%d\n",f[n]-l*k);
	return 0;
}