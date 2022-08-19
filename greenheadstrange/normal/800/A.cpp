#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005 
using namespace std;
long long n, p;
long long num[maxn], ns[maxn];
int main()
{
	scanf("%I64d%I64d", &n, &p);
	long long sum = 0;
	for(int i = 1; i <= n; i++)
		scanf("%I64d%I64d", &num[i], &ns[i]), sum += num[i];
	if(p >= sum)
	{
		printf("-1\n");
		return 0;
	}
	double bgr = 1000000000;
	bgr *= 110000;
	double l = 0, r = bgr;
	while(r - l > 0.00005)
	{
		double mid = (l + r) / 2;
		double nt = 0;
		for(int i = 1; i <= n; i++)
			if(ns[i] >= mid * num[i]) continue;
			else if(p) nt += (mid * num[i] - ns[i]) / p;
			else nt += mid * 2;
		if(nt > mid) r = mid;
		else l = mid;
	}
	printf("%.9lf\n", l);
	return 0;
}