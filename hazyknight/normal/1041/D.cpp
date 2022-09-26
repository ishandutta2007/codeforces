#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <queue>

using namespace std;

const int MAXN = 200005;

int n,h;
int l[MAXN],r[MAXN];

bool ok(int tar)
{
	int tail = 1,dec = 0,len = r[1] - l[1];
	for (int i = 1;i <= n;i++)
	{
		while (tail + 1 <= n && dec + l[tail + 1] - r[tail] < h)
			dec += l[tail + 1] - r[tail],len += r[tail + 1] - l[tail + 1],tail++;
		if (len + h >= tar)
			return true;
		dec -= l[i + 1] - r[i];
		len -= r[i] - l[i];
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> h;
	for (int i = 1;i <= n;i++)
		cin >> l[i] >> r[i];
	int low = h,high = 2000000000;
	while (low < high)
	{
		int mid = low + (high - low + 1) / 2;
		if (ok(mid))
			low = mid;
		else
			high = mid - 1;
	}
	cout << low << endl;
	return 0;
}