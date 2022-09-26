#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n,ans,sum,a,b;

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a >> b;
		sum = sum - a + b;
		ans = max(ans,sum);
	}
	cout << ans << endl;
	return 0;
}