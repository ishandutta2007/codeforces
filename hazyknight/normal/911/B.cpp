#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int n,a,b;
int ans;

int main()
{
	cin >> n >> a >> b;
	for (int i = 1,j;i < n;i++)
	{
		j = n - i;
		ans = max(ans,min(a / i,b / j));
	}
	cout << ans << endl;
	return 0;
}