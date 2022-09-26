#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

struct ANS
{
	int xa,ya,xb,yb,xc,yc;
};

struct PRE
{
	int p1,p2,s;
}pre[MAXN][2][2];

int T,n,m;
int a[MAXN][MAXN];
int f[MAXN][2][2];

char s[MAXN];

vector<ANS> ans;

int popcount(int v)
{
	return v ? popcount(v - (v & -v)) + 1 : 0;
}

void operate(int x,int y,int nx,int ny,bool flag = 0)
{
	if (flag)
		ans.push_back((ANS){0,0,0,0,0,0});
	for (int i = 0;i <= 1;i++)
		for (int j = 0;j <= 1;j++)
			if (x + i != nx || j + y != ny)
			{
				if (flag)
				{
					if (ans.back().xa)
					{
						if (ans.back().xb)
						{
							ans.back().xc = x + i;
							ans.back().yc = y + j;
						}
						else
						{
							ans.back().xb = x + i;
							ans.back().yb = y + j;
						}
					}
					else
					{
						ans.back().xa = x + i;
						ans.back().ya = y + j;
					}
				}
				a[x + i][y + j] ^= 1;
			}
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;i++)
		{
			scanf("%s",s + 1);
			for (int j = 1;j <= m;j++)
				a[i][j] = s[j] - '0';
		}
		ans.clear();
		for (int i = 1;i <= n - 2;i++)
			for (int j = 1;j <= m;j++)
				if (a[i][j])
				{
					if (j < m)
						operate(i,j,i,j + 1,1);
					else
						operate(i,j - 1,i,j - 1,1);
				}
		for (int i = 1;i <= m;i++)
			for (int j = 0;j <= 1;j++)
				for (int k = 0;k <= 1;k++)
					f[i][j][k] = 1e9;
		f[1][a[n - 1][1]][a[n][1]] = 0;
		for (int i = 1;i < m;i++)
			for (int j = 0;j <= 1;j++)
				for (int k = 0;k <= 1;k++)
					if (f[i][j][k] != 1e9)
					{
						int t1 = a[n - 1][i],t2 = a[n][i];
						a[n - 1][i] = j;
						a[n][i] = k;
						for (int l = 0;l < 16;l++)
						{
							if (l & 1)
								operate(n - 1,i,n - 1,i);
							if (l >> 1 & 1)
								operate(n - 1,i,n,i);
							if (l >> 2 & 1)
								operate(n - 1,i,n - 1,i + 1);
							if (l >> 3 & 1)
								operate(n - 1,i,n,i + 1);
							if (!a[n - 1][i] && !a[n][i] && f[i + 1][a[n - 1][i + 1]][a[n][i + 1]] > f[i][j][k] + popcount(l))
							{
								f[i + 1][a[n - 1][i + 1]][a[n][i + 1]] = f[i][j][k] + popcount(l);
								pre[i + 1][a[n - 1][i + 1]][a[n][i + 1]] = (PRE){j,k,l};
							}
							if (l & 1)
								operate(n - 1,i,n - 1,i);
							if (l >> 1 & 1)
								operate(n - 1,i,n,i);
							if (l >> 2 & 1)
								operate(n - 1,i,n - 1,i + 1);
							if (l >> 3 & 1)
								operate(n - 1,i,n,i + 1);
						}
						a[n - 1][i] = t1;
						a[n][i] = t2;
					}
		int t1 = 0,t2 = 0;
		for (int i = m;i > 1;i--)
		{
			int l = pre[i][t1][t2].s;
			if (l & 1)
				operate(n - 1,i - 1,n - 1,i - 1,1);
			if (l >> 1 & 1)
				operate(n - 1,i - 1,n,i - 1,1);
			if (l >> 2 & 1)
				operate(n - 1,i - 1,n - 1,i,1);
			if (l >> 3 & 1)
				operate(n - 1,i - 1,n,i,1);
			int n1 = pre[i][t1][t2].p1,n2 = pre[i][t1][t2].p2;
			t1 = n1;
			t2 = n2;
		}
		printf("%d\n",(int)ans.size());
		for (int i = 0;i < ans.size();i++)
			printf("%d %d %d %d %d %d\n",ans[i].xa,ans[i].ya,ans[i].xb,ans[i].yb,ans[i].xc,ans[i].yc);
	}
	return 0;
}