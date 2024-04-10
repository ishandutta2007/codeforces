#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 505;

int n;
int ans[MAXN][MAXN];

bool ok(int x,int y)
{
	return x >= y && y >= 1 && x <= n && !ans[x][y];
}

int main()
{
	scanf("%d",&n);
	for (int a,i = 1;i <= n;i++)
	{
		scanf("%d",&a);
		int A = a;
		a--;
		ans[i][i] = A;
		int x = i,y = i;
		while (a--)
		{
			if (ok(x - 1,y))
				x--;
			else if (ok(x,y - 1))
				y--;
			else if (ok(x + 1,y))
				x++;
			else if (ok(x,y + 1))
				y++;
			ans[x][y] = A;
		}
	}
	for (int i = 1;i <= n;i++,printf("\n"))
		for (int j = 1;j <= i;j++)
			printf("%d ",ans[i][j]);
	return 0;
}