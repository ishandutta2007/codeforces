// Codeforces Testing Round #1
// Problem C -- Circular RMQ
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

#define N 262144
#define INF 1000000000000LL
#define MID ((l + r) >> 1)

using namespace std;

int n, m;
long long value[N + N], delta[N + N];

void update(int l, int r)
{
	value[l + r] = min(value[l + MID] + delta[l + MID], value[MID + r] + delta[MID + r]);
}

void inc(int l, int r, int a, int b, int c)
{
	if(a >= b)
		return;
	if(l == a && r == b)
		delta[l + r] += c;
	else
	{
		inc(l, MID, a, min(b, MID), c);
		inc(MID, r, max(a, MID), b, c);
		update(l, r);
	}
}

long long rmq(int l, int r, int a, int b)
{
	if(a >= b)
		return INF;
	if(l == a && r == b)
		return value[l + r] + delta[l + r];
	return min(rmq(l, MID, a, min(b, MID)), rmq(MID, r, max(a, MID), b)) + delta[l + r];
}

int main()
{
	memset(value, 0, sizeof(value));
	memset(delta, 0, sizeof(delta));
	scanf("%d", &n);
	for(int i = 0; i != n; ++ i)
	{
		int a;
		scanf("%d", &a);
		inc(0, N, i, i + 1, a);
	}
	for(scanf("%d\n", &m); m; -- m)
	{
		char t[1024];
		gets(t);
		int a, b, c = INT_MAX;
		sscanf(t, "%d%d%d", &a, &b, &c);
		if(c != INT_MAX)
		{
			if(a < b + 1)
				inc(0, N, a, b + 1, c);
			else
			{
				inc(0, N, a, n, c);
				inc(0, N, 0, b + 1, c);
			}
		}
		else
		{
			if(a < b + 1)
				printf("%I64d\n", rmq(0, N, a, b + 1));
			else
				printf("%I64d\n", min(rmq(0, N, a, n), rmq(0, N, 0, b + 1)));
		}
	}
	return 0;
}