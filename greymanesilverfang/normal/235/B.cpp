#include <cstdio>
using namespace std;
double p[100001];

int main()
{
	int n; scanf("%d", &n);
	double res = 0, cur = 0;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lf", &p[i]);
		res += (cur += ++p[i - 1]) *= p[i];
	}
	printf("%.8f", res);
}