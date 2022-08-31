#include <bits/stdc++.h>

using namespace std;

int n;

map<char,int> dx,dy;

char s[5005];

int main()
{
	dx['L'] = -1;
	dx['R'] = 1;
	dy['U'] = 1;
	dy['D'] = -1;
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",s + 1);
		n = strlen(s + 1);
		int X = 0,Y = 0;
		bool ok = 0;
		for (int i = 1;i <= n;i++)
		{
			int nx = X + dx[s[i]],ny = Y + dy[s[i]];
			int xx = 0,yy = 0;
			for (int j = 1;j <= n;j++)
			{
				int nxx = xx + dx[s[j]],nyy = yy + dy[s[j]];
				if (nxx == nx && nyy == ny)
					continue;
				xx = nxx,yy = nyy;
			}
			if (xx == 0 && yy == 0)
			{
				ok = 1;
				printf("%d %d\n",nx,ny);
				break;
			}
			X = nx;
			Y = ny;
		}
		if (!ok)
			puts("0 0\n");
	}
	return 0;
}