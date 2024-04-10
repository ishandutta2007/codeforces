#include <bits/stdc++.h>

using namespace std;

int n,m,P,ans;
int f[1 << 15];
int bit[1 << 15];

char c[200000][65];

bitset<200000> s[65];
bitset<200000> p[20];
vector<int> v;

int path[65];
int isans[65];

int rrand()
{
	return rand() & ((1 << 15) - 1);
}

int Rand()
{
	return rrand() << 15 | rrand();
}

int main()
{
	srand(time(0));
	scanf("%d%d%d",&n,&m,&P);
	for (int i = 0;i < n;i++)
	{
		scanf("%s",c[i]);
		for (int j = 0;j < m;j++)
			if (c[i][j] == '1')
				s[j][i] = 1;
	}
	for (int i = 0;i < (1 << 15);i++)
		bit[i] = bit[i >> 1] + (i & 1);
	p[0].set();
	for (int i = 1;i <= 20;i++)
	{
		int t = Rand() % n;
		v.clear();
		memset(f,0,sizeof(f));
		for (int j = 0;j < m;j++)
			if (c[t][j] == '1')
				v.push_back(j);
		for (int j = 0;j < n;j++)
		{
			int S = 0;
			for (int k = 0;k < v.size();k++)
				if (c[j][v[k]] == '1')
					S += 1 << k;
			f[S]++;
		}
		int N = (1 << v.size());
		for (int j = 1;j < N;j <<= 1)
			for (int k = 0;k < N;k += j << 1)
				for (int l = 0;l < j;l++)
					f[k + l] += f[j + k + l];
		for (int j = 0;j < N;j++)
			if (f[j] * 2 >= n && bit[j] > ans)
			{
				ans = bit[j];
				memset(isans,0,sizeof(isans));
				for (int k = 0;k < v.size();k++)
					if (j >> k & 1)
						isans[v[k]] = 1;
			}
	}
	for (int i = 0;i < m;i++)
		printf("%d",isans[i]);
	printf("\n");
	return 0;
}