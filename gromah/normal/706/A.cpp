#include <cmath>
#include <cstdio>
using namespace std;

int a, b, n, x, y, v;
double Min;

int main()
{
	scanf("%d%d%d", &a, &b, &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d%d%d", &x, &y, &v);
		double dis = sqrt((x - a) * (x - a) + (y - b) * (y - b));
		double ti = dis / v;
		if (ti < Min || i == 1)
			Min = ti;
	}
	printf("%.7lf\n", Min);
	return 0;
}