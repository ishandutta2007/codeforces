#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

struct problem
{
	int tim;
	int a;
	int ori;
	bool operator < (const problem & p)const
	{
		return tim < p.tim;
	}
}a[200005];

int n,T,top;
int cho[200005];

bool check(int tar)
{
	top = 0;
	if (tar == 0)
		return true;
	int cnt = 0,sum = 0;
	for (int i = 1;i <= n;i++)
	{
		if (a[i].a >= tar)
			cnt++,sum += a[i].tim,cho[++top] = a[i].ori;
		if (cnt == tar)
			break;
	}
	if (cnt != tar || sum > T)
		return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> T;
	for (int i = 1;i <= n;i++)
		cin >> a[i].a >> a[i].tim,a[i].ori = i;
	sort(a + 1,a + n + 1);
	int low = 0,high = n;
	while (low < high)
	{
		int mid = (low + high + 1) >> 1;
		if (check(mid))
			low = mid;
		else
			high = mid - 1;
	}
	check(low);
	cout << low << endl;
	cout << top << endl;
	for (int i = 1;i <= top;i++)
		cout << cho[i] << ' ';
	cout << endl;
	return 0;
}