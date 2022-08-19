#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[5];
int otp(int a, int b)
{
	printf("1 %d %d\n", a, b);
	fflush(stdout);
	scanf("%s", &s);
	if(s[0] == 'N') return 1;
	else return 0;
}
int get(int l, int r)
{
	if(l == r) return l;
	int mid = (l + r) >> 1;
	int ls = (l + mid) >> 1;
	int rs = (mid + 1 + r) >> 1;
	if(otp(ls, rs)) return get(mid + 1, r);
	else return get(l, mid);
} 
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int nans = get(1, n);
	int ans2 = 0;
	if(nans == 1) ans2 = get(2, n);
	else if(nans == n) ans2 = get(1, n - 1);
	else
	{
		if(n - nans > nans - 1)
			if(otp(1, nans * 2 - 2)) ans2 = get(nans + 1, n);
			else ans2 = get(1, nans - 1);
		else
			if(otp(n, 2 * nans - n + 1)) ans2 = get(1, nans - 1);
			else ans2 = get(nans + 1, n);
	}
	printf("2 %d %d\n", nans, ans2);
	fflush(stdout);
	return 0;
}