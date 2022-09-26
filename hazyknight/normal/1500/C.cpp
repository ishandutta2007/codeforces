#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1505;

int n,m,tot;
int ans[MAXN];
int len[MAXN];
int tmp[MAXN];
int cnt[MAXN];

vector<int> a[MAXN];
vector<int> b[MAXN];
vector<int> req[MAXN];

int K;

bool vis[MAXN];
bool mark[MAXN];

queue<int> Q;

bool cmp(const vector<int> &a,const vector<int> &b)
{
	return a[K] < b[K];
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
	{
		a[i].resize(m + 1);
		for (int j = 1;j <= m;j++)
			scanf("%d",&a[i][j]);
	}
	for (int i = 1;i <= n;i++)
	{
		b[i].resize(m + 1);
		for (int j = 1;j <= m;j++)
			scanf("%d",&b[i][j]);
	}
	for (int i = 1;i < n;i++)
		for (int j = 1;j <= m;j++)
			if (b[i + 1][j] < b[i][j])
			{
				req[i].push_back(j);
				cnt[j]++;
			}
	for (int i = 1;i <= m;i++)
		if (!cnt[i])
			Q.push(i);
	while (!Q.empty())
	{
		bool flag = 0;
		int i = Q.front();
		Q.pop();
		vis[i] = 1;
		int lst = 0;
		K = i;
		for (int j = 2;j <= n;j++)
			if (len[j] > len[j - 1])
			{
				stable_sort(a + lst + 1,a + j,cmp);
				lst = j - 1;
			}
		stable_sort(a + lst + 1,a + n + 1,cmp);
		for (int j = 2;j <= n;j++)
			if (len[j] > len[j - 1] || b[j][i] > b[j - 1][i])
			{
				tmp[j] = tmp[j - 1] + 1;
				if (!mark[j - 1])
				{
					mark[j - 1] = 1;
					for (int k = 0;k < req[j - 1].size();k++)
						if (!--cnt[req[j - 1][k]])
							Q.push(req[j - 1][k]);
				}
			}
		for (int j = 1;j <= n;j++)
			len[j] = tmp[j];
		ans[++tot] = i;
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (a[i][j] != b[i][j])
			{
				puts("-1");
				return 0;
			}
	printf("%d\n",tot);
	for (int i = tot;i >= 1;i--)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}