#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int n,a,b,c,d;
int ans;

int main()
{
	cin >> n >> a >> b >> c >> d;
	int sum = a + b + c + d;
	for (int i = 1;i < n;i++)
	{
		cin >> a >> b >> c >> d;
		if (a + b + c + d > sum)
			ans++;
	}
	cout << ans + 1 << endl;
	return 0;
}