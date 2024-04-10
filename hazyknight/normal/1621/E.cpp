#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

int T,n,m,N;
int a[MAXN];
int MIN[MAXN << 2];
int laz[MAXN << 2];

ll sum[MAXN];

vector<int> b[MAXN];

void add(int o,int v)
{
	laz[o] += v;
	MIN[o] += v;
}

void pushdown(int o)
{
	if (laz[o])
	{
		add(o << 1,laz[o]);
		add(o << 1 | 1,laz[o]);
		laz[o] = 0;
	}
}

void modify(int o,int l,int r,int x,int y,int v)
{
	if (l >= x && r <= y)
	{
		add(o,v);
		return;
	}
	pushdown(o);
	int mid = l + r >> 1;
	if (mid >= x)
		modify(o << 1,l,mid,x,y,v);
	if (mid + 1 <= y)
		modify(o << 1 | 1,mid + 1,r,x,y,v);
	MIN[o] = min(MIN[o << 1],MIN[o << 1 | 1]);
}

int main()
{
	N = 1e5;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		sort(a + 1,a + n + 1);
		reverse(a + 1,a + n + 1);
		reverse(a + 1,a + m + 1);
		for (int i = 1;i <= n;i++)
			modify(1,1,N,1,a[i],1);
		for (int i = 1;i <= m;i++)
		{
			int c;
			scanf("%d",&c);
			b[i].resize(c);
			sum[i] = 0;
			for (int j = 0;j < b[i].size();j++)
			{
				scanf("%d",&b[i][j]);
				sum[i] += b[i][j];
			}
			modify(1,1,N,1,(sum[i] - 1) / b[i].size() + 1,-1);
		}
		for (int i = 1;i <= m;i++)
		{
			for (int j = 0;j < b[i].size();j++)
			{
				modify(1,1,N,1,(sum[i] - 1) / b[i].size() + 1,1);
				modify(1,1,N,1,(sum[i] - b[i][j] - 1) / (b[i].size() - 1) + 1,-1);
				printf("%d",(MIN[1] >= 0));
				modify(1,1,N,1,(sum[i] - b[i][j] - 1) / (b[i].size() - 1) + 1,1);
				modify(1,1,N,1,(sum[i] - 1) / b[i].size() + 1,-1);
			}
		}
		printf("\n");
		for (int i = 1;i <= n;i++)
			modify(1,1,N,1,a[i],-1);
		for (int i = 1;i <= m;i++)
			modify(1,1,N,1,(sum[i] - 1) / b[i].size() + 1,1);
	}
	return 0;
}