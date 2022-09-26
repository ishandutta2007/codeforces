#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>

using namespace std;

int n,L,a;
int pre,ans;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> L >> a;
	for (int t,l,i = 1;i <= n;i++)
	{
		cin >> t >> l;
		ans += (t - pre) / a;
		pre = t + l;
	}
	ans += (L - pre) / a;
	cout << ans << endl;
	return 0;
}