#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;

int n;

long long ans;
long long f[55];

string s;

int main()
{
	cin >> n >> s;
	f[1] = 1;
	for (int i = 2;i <= n;i++)
		f[i] = f[i - 1] * 2 + 1;
	for (int i = 0;i < n;i++)
		if (s[i] == 'B')
			ans += f[i] + 1;
	cout << ans << endl;
	return 0;
}