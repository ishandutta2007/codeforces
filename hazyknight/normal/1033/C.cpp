#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n;
int a[100005];
int pos[100005];

bool ans[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i],pos[a[i]] = i;
	for (int i = n;i >= 1;i--)
	{
		ans[pos[i]] = 1;
		for (int j = pos[i];ans[pos[i]] && j >= 1;j -= i)
			if (a[j] > i && ans[j])
				ans[pos[i]] = 0;
		for (int j = pos[i];ans[pos[i]] && j <= n;j += i)
			if (a[j] > i && ans[j])
				ans[pos[i]] = 0;
	}
	for (int i = 1;i <= n;i++)
		cout << char('A' + ans[i]);
	cout << endl;
	return 0;
}