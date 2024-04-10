#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int T,n;
int x[MAXN];
int y[MAXN];

double ans1,ans2;

bool cmp(const int &a,const int &b)
{
	return abs(a) < abs(b);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		ans1 = ans2 = 0;
		scanf("%d",&n);
		int xx = 0,yy = 0,X,Y;
		for (int i = 1;i <= 2 * n;i++)
		{
			scanf("%d%d",&X,&Y);
			if (!X)
				y[++yy] = Y;
			else
				x[++xx] = X;
		}
		sort(x + 1,x + n + 1,cmp);
		sort(y + 1,y + n + 1,cmp);
		for (int i = 1;i <= n;i++)
			ans1 += sqrt((double)x[i] * x[i] + (double)y[i] * y[i]);
		printf("%.10lf\n",ans1);
	}
	return 0;
}