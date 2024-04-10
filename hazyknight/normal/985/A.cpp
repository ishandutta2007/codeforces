#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <queue>
#include <set> 
#include <vector>
#include <ctime>

using namespace std;

int n;
int a[105];

int main()
{
	cin >> n;
	for (int i = 1;i <= n / 2;i++)
		cin >> a[i];
	sort(a + 1,a + n / 2 + 1);
	int ans1 = 0,ans2 = 0;
	for (int i = 1;i <= n;i += 2)
		ans1 += abs(a[(i + 1) / 2] - i);
	for (int i = 2;i <= n;i += 2)
		ans2 += abs(a[i / 2] - i);
	cout << min(ans1,ans2) << endl;
	return 0;
}