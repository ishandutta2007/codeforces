#include <cstdio>
#include <queue>

long long sqr(long long x)
{
	return x * x;
}

long long calc(int size, int cnt)
{
	int big = size % cnt;
	int small = cnt - big;
	size = size / cnt;
	return sqr(size + 1) * big + sqr(size) * small;
}

struct data {
	int size, cnt;
	data() {}
	data(int s, int c) {
		size = s;
		cnt = c;
	}
	long long val() const {
		return calc(size, cnt) - calc(size, cnt + 1);
	}
	bool operator < (const data &other) const {
		return val() < other.val();
	}
};

std::priority_queue<data> heap;

int main()
{
	int n, k; scanf("%d%d", &n, &k);
	long long res = 0;
	for (int i = 1; i <= n; ++i)
	{
		int a; scanf("%d", &a);
		heap.push(data(a, 1));
		res += 1LL * a * a;
	}
	for (int i = 1; i <= k - n; ++i)
	{
		data d = heap.top();
		heap.pop();
		res -= d.val();
		++d.cnt;
		heap.push(d);
	}
	printf("%lld\n", res);
}