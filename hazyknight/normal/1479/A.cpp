#include <bits/stdc++.h>

using namespace std;

int query(int p)
{
	cout << "? " << p << endl;
	cout.flush();
	int res = 0;
	cin >> res;
	return res;
}

int main()
{
	int n;
	cin >> n;
	int low = 1,high = n;
	while (low < high)
	{
		int mid = low + high >> 1;
		int v1 = query(mid),v2 = query(mid + 1);
		if (v1 > v2)
			low = mid + 1;
		else
			high = mid;
	}
	cout << "! " << low << endl;
	return 0;
}