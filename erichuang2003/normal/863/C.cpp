#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;

long long k;

int a,b;
int A[4][4];
int B[4][4];

pair<int,int> c[4][4];

int now;
int t[4][4];

int main()
{
	cin >> k >> a >> b;
	for (int i = 1;i <= 3;i++)
		for (int j = 1;j <= 3;j++)
			cin >> A[i][j];
	for (int i = 1;i <= 3;i++)
		for (int j = 1;j <= 3;j++)
			cin >> B[i][j];
	long long ca = 0,cb = 0;
	for (int i = 1;i <= k;i++)
	{
		if ((a - b + 3) % 3 == 1)
			ca++;
		else if ((b - a + 3) % 3 == 1)
			cb++;
		if (t[a][b])
		{
			now = i;
			break;
		}
		t[a][b] = i;
		c[a][b] = make_pair(ca,cb);
		int ta = a,tb = b;
		a = A[ta][tb];
		b = B[ta][tb];
	}
	if (now)
	{
		k -= now - 1;
		ca += (k / (now - t[a][b])) * (ca - c[a][b].first);
		cb += (k / (now - t[a][b])) * (cb - c[a][b].second);
		if ((a - b + 3) % 3 == 1)
			ca--;
		else if ((b - a + 3) % 3 == 1)
			cb--;
		k %= (now - t[a][b]);
		for (int i = 1;i <= k;i++)
		{
			if ((a - b + 3) % 3 == 1)
				ca++;
			else if ((b - a + 3) % 3 == 1)
				cb++;
			int ta = a,tb = b;
			a = A[ta][tb];
			b = B[ta][tb];
		}
	}
	cout << ca << ' ' << cb << endl;
	return 0;
}