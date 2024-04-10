#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
const int M = 300;
int dp[M][M][M];
int nex[N][M];
char str[N];
int rec[M];
char s1[M];
char s2[M];
char s3[M];
void getmin(int &x, int y)
{
	if (y == -1) return;
	if (x == -1) x = y;
	else x = min(x, y);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int len, q;
	scanf("%d%d", &len, &q);
	scanf("%s", str + 1);
	MEM(dp, -1);
	MEM(rec, -1);
	for (int i = len; i >= 0; i--)
	{
		for (int j = 'a'; j <= 'z'; j++)
		{
			nex[i][j] = rec[j];
		}
		rec[str[i]] = i;
	}
	int A, B, C;
	A = B = C = 0;
	dp[0][0][0] = 0;
	while (q--)
	{
		char op, c;
		int pos;
		scanf(" %c %d", &op, &pos);
		if (op == '+')
		{
			scanf(" %c", &c);
			int x = A, y = B, z = C;
			if (pos == 1)
			{
				s1[A++] = c;
				for (int i = 0; i <= B; i++)
				{
					for (int j = 0; j <= C; j++)
					{
						if (dp[x][i][j] != -1) getmin(dp[A][i][j], nex[dp[x][i][j]][c]);
						if (dp[A][i][j] != -1)
						{
							if (i < B)
							{
								getmin(dp[A][i + 1][j], nex[dp[A][i][j]][s2[i]]);
							}

							if (j < C)
							{
								getmin(dp[A][i][j + 1], nex[dp[A][i][j]][s3[j]]);
							}
						}
					}
				}
			}
			if (pos == 2)
			{
				s2[B++] = c;
				for (int i = 0; i <= A; i++)
				{
					for (int j = 0; j <= C; j++)
					{
						if (dp[i][y][j] != -1) getmin(dp[i][B][j], nex[dp[i][y][j]][c]);
						if (dp[i][B][j] != -1)
						{
							if (i < A)
							{
								getmin(dp[i + 1][B][j], nex[dp[i][B][j]][s1[i]]);
							}
							if (j < C)
							{
								getmin(dp[i][B][j + 1], nex[dp[i][B][j]][s3[j]]);
							}
						}
					}
				}
			}
			if (pos == 3)
			{
				//cout << "***" << endl;
				s3[C++] = c;
				for (int i = 0; i <= A; i++)
				{
					for (int j = 0; j <= B; j++)
					{
						if (dp[i][j][z] != -1) getmin(dp[i][j][C], nex[dp[i][j][z]][c]);
						if (dp[i][j][C] != -1)
						{
							if (i < A)
							{
								getmin(dp[i + 1][j][C], nex[dp[i][j][C]][s1[i]]);
							}
							if (j < B)
							{
								getmin(dp[i][j + 1][C], nex[dp[i][j][C]][s2[j]]);
							}
						}
					}
				}
			}
		}
		else
		{
			if (pos == 1)
			{
				for (int i = 0; i <= 250; i++)
				{
					for (int j = 0; j <= 250; j++)
					{
						dp[A][i][j] = -1;
					}
				}
				A--;
			}
			if (pos == 2)
			{
				for (int i = 0; i <= 250; i++)
				{
					for (int j = 0; j <= 250; j++)
					{
						dp[i][B][j] = -1;
					}
				}
				B--;
			}
			if (pos == 3)
			{
				for (int i = 0; i <= 250; i++)
				{
					for (int j = 0; j <= 250; j++)
					{
						dp[i][j][C] = -1;
					}
				}
				C--;
			}
		}
		if (dp[A][B][C] != -1) puts("YES");
		else puts("NO");

	}
	return 0;
}