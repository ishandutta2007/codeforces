#include <cstdio>
#include <cassert>
#include <algorithm>
long long a, b, c;

void move(long long x)
{
	printf("%lld\n", x); fflush(stdout);
	int id; scanf("%d", &id);
	if (id == 1)
		a += x;
	else if (id == 2)
		b += x;
	else if (id == 3)
		c += x;
	else
		exit(0);
}

int main()
{
	scanf("%lld%lld%lld", &a, &b, &c);
	printf("First\n"); fflush(stdout);
	move(std::max(a, std::max(b, c)));
	long long max1 = std::max(a, std::max(b, c));
	move(max1 - a + max1 - b + max1 - c);
	long long max2 = std::max(a, std::max(b, c));
	move(max2 - max1);
	assert(false);
}