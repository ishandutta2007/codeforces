#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#define ll long long
#define maxn 75
using namespace std;
bool can[35][maxn * 31][maxn];
int num[maxn];
//   
int nnum[maxn];
int w[maxn][maxn];
int nx[35][maxn * 31][maxn];
int ncnt[maxn];
struct th
{
	int id, nnum;
	bool operator < (const th &a)const
	{
		return nnum < a.nnum;
	}
}p[maxn];
int main()
{
	int m;
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
		scanf("%d", &num[i]);
	sort(num + 1, num + 1 + m);
	bool flag = 0;
	for(int n = 1; n < maxn; n++)
	{
		if(flag) break;
		memset(can, 0, sizeof(can));
		can[m][n * (n - 1) / 2][n + 1] = 1;
		for(int j = n; j >= 1; j--)
			for(int q = 0; q < j * 31; q++)
				for(int r = 0; r <= m; r++)
				{
					int ns = q + num[r];
					if(r && ns >= j * (j - 1) / 2 && can[r][ns][j + 1]) 
						can[r][q][j] = 1, nx[r][q][j] = num[r];
					else if(r != m) 
					{
						int ns2 = q + num[r + 1];
						if(ns2 >= j * (j - 1) / 2 && can[r + 1][ns2][j + 1])
							can[r][q][j] = 1, nx[r][q][j] = num[r + 1];
					}
				}
		if(can[0][0][1])
		{
			printf("%d\n", n);
			flag = 1;
			int nr = 1, ns = 0, npl = 1;
			for(int j = 1; j <= n; j++)
			{
				nnum[j] = nx[nr][ns][npl], 
				ns += nnum[j];
				if(nnum[j] == num[nr + 1]) nr++;
				npl++;
			}
			for(int j = n; j >= 1; j--)
				p[j].id = j, p[j].nnum = nnum[j];
			for(int j = n; j >= 1; j--)
			{
			//	cout<<"NS"<<j<<endl;
				sort(p + 1, p + j + 1);
			//	cout<<"STP"<<endl;
				for(int q = j - 1; q >= p[j].nnum + 1; q--)
					w[p[q].id][p[j].id] = 1, p[q].nnum--;
			//	cout<<"GET"<<j - p[j].nnum<<endl;
				for(int q = p[j].nnum; q; q--)
					w[p[j].id][p[q].id] = 1;
			}
			for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j <= n; j++)
					printf("%d", w[i][j]);
				printf("\n");
			}
		}
	}
	if(!flag) printf("=\n");
	return 0;
}