#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <ctime>
#include <queue>

using namespace std;

int n;

string s;

int main()
{
	cin >> n;
	int low = 0,high = 1000000000;
	for (int i = 1;i <= n / 2;i++)
	{
		int mid = (low + high) >> 1;
		cout << mid << ' ' << 0 << endl;
		fflush(stdout);
		cin >> s;
		if (s == "black")
			low = mid + 1;
		else
			high = mid - 1;
	}
	int ansx = (low + high) >> 1;
	low = 0,high = 1000000000;
	for (int i = 1;i <= (n + 1) / 2;i++)
	{
		int mid = (low + high) >> 1;
		cout << 0 << ' ' << mid << endl;
		fflush(stdout);
		cin >> s;
		if (s == "black")
			low = mid + 1;
		else
			high = mid - 1;
	}
	int ansy = (low + high) >> 1;
	cout << ansx << ' ' << 0 << ' ' << 0 << ' ' << ansy << endl;
	fflush(stdout);
	return 0;
}