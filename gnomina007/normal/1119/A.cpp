#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<long long>c(n);
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	int ans=-1;
	for (int i = 1; i < n; i++)
	{
		if (c[0] != c[i])
		{
			ans = max(ans, i);
		}
	}
	for (int i = 0; i < n-1; i++)
	{
		if (c[n-1] != c[i])
		{
			ans = max(ans, n-1-i);
		}
	}
	cout << ans << endl;
//	cin >> n;
}