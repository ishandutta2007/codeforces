#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define ll long long
#define maxn 200005
using namespace std;
int ns[maxn];
bool hv[50];
int n, m;
int nx[4] = {1, -1};
bool flag = 0;
void dfs(int a)
{
//	cout<<a<<" "<<ns[1]<<" "<<ns[2]<<" "<<ns[3]<<" "<<ns[4]<<endl;
	if(flag) return;
	if(a == n * m + 1)
	{
		printf("YES\n");
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
				printf("%d ", ns[(i - 1) * m + j]);
			printf("\n");
		}
		flag = 1;
		return ;
	}
	for(int i = 1; i <= n * m; i++)
	{
		if(!hv[i])
		{
			bool fl = 1;
			ns[a] = i;
			for(int j = 0; j < 4; j++)
			{
				int ext = a + nx[j];
				if(ext > a) continue;
				if(ext > n * m || ext <= 0) continue;
				if(a % m == 1 && j == 1) continue;
				if(a % m == 0 && j == 0) continue;
				int nss = ns[ext];
				for(int k = 0; k < 4; k++)
				{
					int exts = i + nx[k];
					
					if(exts > n * m || exts <= 0) continue;
					if(i % m == 1 && k == 1) continue;
					if(i % m == 0 && k == 0) continue;
					if(nss == exts) 
					{
						fl = 0;
					}
				}
			}
			if(!fl) 
				continue;
			hv[i] = 1, 
			dfs(a + 1), 
			hv[i] = 0;
		}
	}
}
int cal(int a, int b)
{
	return (a - 1) * m + b;
}
int main()
{
	scanf("%d%d", &n, &m);
	nx[2] = m, nx[3] = -m;
	if(n <= 7 && m <= 7)
	{
		dfs(1);
		if(!flag)
			printf("NO\n");
	}
	else
	{

		if(n >= 8)
		{
			for(int i = 1; i <= m; i++)
			{
				int nst = i & 1;
				if(!nst) nst = 2;
				for(int j = nst; j <= n; j += 2)
					ns[cal(j, i)] = cal(j, i);
				nst = 3 - nst;
				int ncnt = 0;
				for(int j = nst; j <= n; j+= 2)
				{
					int nxt = j + 4;
					if(nxt > n)
					{
						ncnt++;
						if(ncnt == 1)
							nxt = nst;
						else nxt = nst + 2;
					}
					ns[cal(j, i)] = cal(nxt, i);
				}
			}
		}
		else
		{
			for(int i = 1; i <= n; i++)
			{
				int nst = i & 1;
				if(!nst) nst = 2;
				for(int j = nst; j <= m; j += 2)
					ns[cal(i, j)] = cal(i, j);
				nst = 3 - nst;
				int ncnt = 0;
				for(int j = nst; j <= m; j += 2)
				{
					int nxt = j + 4;
					if(j + 4 > m) 
					{
						ncnt++;
						if(ncnt == 1)
							nxt = nst;
						else nxt = nst + 2;
					}
					ns[cal(i, j)] = cal(i, nxt);
				}
			}
		}		
		printf("YES\n");
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
				printf("%d ", ns[(i - 1) * m + j]);
			printf("\n");
		}
	}
	return 0;
}