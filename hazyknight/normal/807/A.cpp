#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int MAXN = 1005;

int n;
int a[MAXN],b[MAXN];

int main()
{
	cin >> n;
	bool flag = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> b[i];
		if (a[i] != b[i])
		{
			cout << "rated" << endl;
			return 0;
		}
		if (i > 1 && a[i] > a[i - 1])
			flag = true;
	}
	if (flag)
		cout << "unrated" << endl;
	else
		cout << "maybe" << endl;
	return 0;
}