#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
	int n,a,b,c,ans = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a >> b >> c;
		if (a + b + c >= 2)
			ans++;
	}
	cout << ans << endl;
	return 0;
}