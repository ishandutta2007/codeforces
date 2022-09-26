#include <iostream>

using namespace std;

int main()
{
	int n,k,ans = (1 << 30) - 1;
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		int a;
		cin >> a;
		if (k % a == 0)
			ans = min(ans,k / a);
	}
	cout << ans << endl;
	return 0;
}