#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <iomanip>

using namespace std;

int n,m,res;
int q[35];

int ask(int y)
{
	cout << y << endl;
	fflush(stdout);
	cin >> res;
	if (res == 0)
		exit(0);
	return res;
}

int main()
{
	cin >> m >> n;
	for (int i = 0;i < n;i++)
		q[i] = ask(1);
	int low = 1,high = m,cur = 0;
	while (low < high)
	{
		int mid = (low + high) >> 1;
		if (ask(mid) * q[cur] == 1)
			low = mid + 1;
		else
			high = mid - 1;
		(cur += 1) %= n;
	}
	ask(low);
	return 0;
}