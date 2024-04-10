#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int n;

string a,b;

long long cnt[2][2];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> a >> b;
	for (int i = 0;i < n;i++)
		cnt[a[i] - '0'][b[i] - '0']++;
	cout << cnt[0][1] * cnt[1][0] + cnt[1][1] * cnt[0][0] + cnt[1][0] * cnt[0][0] << endl;
	return 0;
}