#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <fstream>

using namespace std;

int n;

long long l,w,ans;

vector<int> pos,neg;

bool ok(long long p1,long long p2)
{
	if (p1 >= p2 + l)
		return false;
	long long mid = (p1 + l + p2) / 2;
	long long t = (p2 + l - p1) / 2;
	if (mid == 0)
		return true;
	if (mid < 0)
		return -t * w < mid;
	return t * w > mid;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> l >> w;
	l *= 2;
	for (int x,v,i = 1;i <= n;i++)
	{
		cin >> x >> v;
		x *= 2;
		if (v == -1)
			neg.push_back(x);
		else
			pos.push_back(x);
	}
	sort(pos.begin(),pos.end());
	sort(neg.begin(),neg.end());
	ans = 0;
	int head = 0,tail = 0;
	while (tail < neg.size() && !ok(pos[0],neg[tail]))
		tail++;
	tail--;
	for (int i = 0;i < pos.size();i++)
	{
		while (tail + 1 < neg.size() && ok(pos[i],neg[tail + 1]))
			tail++;
		while (head < neg.size() && !ok(pos[i],neg[head]))
		{
			head++;
			if (tail < head)
				tail = head - 1;
		}
		if (head < neg.size() && tail < head)
			tail = head;
		ans += tail - head + 1;
	}
	cout << ans << endl;
	/*
	ans = 0;
	for (int i = 0;i < pos.size();i++)
		for (int j = 0;j < neg.size();j++)
			if (ok(pos[i],neg[j]))
			{
				cout << i << ' ' << j << endl;
				ans++;
			}
	cout << ans << endl;
	*/
	return 0;
}
/*
5 1 2
-4 -1
-3 1
5 -1
-1 -1
0 1
*/