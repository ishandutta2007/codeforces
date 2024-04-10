#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double db;

int T,a,b;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&a,&b);
		if ((a + b) & 1)
		{
			int A = (a + b + 1) / 2,B = (a + b) / 2;
			int ta = min(a,A),tb = min(b,B);
			int MIN = a + b - ta - tb;
			ta = min(a,B),tb = min(b,A);
			int MAX = ta + tb;
			A = (a + b) / 2,B = (a + b + 1) / 2;
			ta = min(a,A),tb = min(b,B);
			MIN = min(MIN,a + b - ta - tb);
			ta = min(a,B),tb = min(b,A);
			MAX = max(MAX,ta + tb);
			printf("%d\n",MAX - MIN + 1);
			for (int i = MIN;i <= MAX;i++)
				printf("%d ",i);
			printf("\n");
		}
		else
		{
			int A = (a + b) / 2,B = (a + b) / 2;
			int ta = min(a,A),tb = min(b,B);
			int MIN = a + b - ta - tb;
			ta = min(a,B),tb = min(b,A);
			int MAX = ta + tb;
			printf("%d\n",(MAX - MIN) / 2 + 1);
			for (int i = MIN;i <= MAX;i += 2)
				printf("%d ",i);
			printf("\n");
		}
	}
	return 0;
}