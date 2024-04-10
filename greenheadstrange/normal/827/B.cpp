#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
int up(int a, int b)
{
	int ans = a / b;
	if(a % b) ans++;
	return ans;
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int lst = n - k - 1;
	int ans1 = up(lst, k);
	lst -= ans1;
	int ans2 = up(lst, k - 1);
	printf("%d\n", ans1 + ans2 + 2);
	lst = n - k - 1;
	int cnt = 2;
	for(int i = 1; i <= k; i++)
	{
		int len = up(lst, k - i + 1);
		lst -= len;
		int lpl = 1;
		for(int j = 1; j <= len + 1; j++)
			printf("%d %d\n", lpl, cnt), lpl = cnt, cnt++;
	}
	return 0;	
}