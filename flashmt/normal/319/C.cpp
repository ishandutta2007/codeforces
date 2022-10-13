#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const long long oo = 1LL << 60;

struct hull
{
	long long A[100100], B[100100];
	double xLeft[100100];
	int head, tail;
	
	hull() {}
	
	void reset()
	{
		head = 1; tail = 0;
	}
	
	long long get(long long x)
	{
		while (head < tail && xLeft[head + 1] <= x) head++;
		xLeft[head] = x;
		return A[head] * x + B[head];
	}
	
	void add(long long AA, long long BB)
	{
		double x = 1e-18;
		while (tail >= head)
		{
			if (AA == A[tail]) return;
			x = 1.0 * (B[tail] - BB) / (AA - A[tail]);
			if (tail == head || x >= xLeft[tail]) break;
			tail--;
		}
		A[++tail] = AA; B[tail] = BB; xLeft[tail] = x;
	}
};

int n, height[100100], cost[100100];
long long f[100100];
hull h;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", height + i);
	for (int i = 1; i <= n; i++) scanf("%d", cost + i);
	
	h.reset();
	h.add(cost[1], f[1]);
	
	for (int i = 2; i <= n; i++)
	{
		f[i] = h.get(height[i]);
		h.add(cost[i], f[i]);
	}
	
	cout << f[n] << endl;
}