#include <cstdio>
#include <algorithm>
#include <numeric>

using ll = long long;

ll a[3];
int res, ord[3];
bool cmp(int x, int y){return a[x]<a[y];}

int main()
{
	scanf("%lld%lld%lld", a, a+1, a+2);
	std::iota(ord, ord+3, 0);
	std::sort(ord, ord+3, cmp);
	printf("First\n");
	fflush(stdout);
	bool f=1;
	for(;;)
	{
		ll y;
		if(f) y=a[ord[2]]-a[ord[0]];
		else
		{
			y=a[ord[2]]*2-a[ord[1]]-a[ord[0]];
			if(a[ord[2]] - a[ord[1]] == a[ord[1]] - a[ord[0]])
				y = a[ord[1]] - a[ord[0]];
		}
		f=0;
		printf("%lld\n", y);
		fflush(stdout);
		scanf("%d", &res);
		if(res == 0) return 0;
		if(res == -1) return 0;
		a[res-1] += y;
		std::sort(ord, ord+3, cmp);
	}
	return 0;
}