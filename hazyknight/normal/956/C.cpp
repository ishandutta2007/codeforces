#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

long long n,MAX,cnt,ans;
long long m[100005];

bool mark[100005];

vector<int> add;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	m[0] = -1;
	for (int i = 1;i <= n;i++)
	{
		cin >> m[i];
		add.push_back(i);
		if (m[i] > m[MAX])
		{
			MAX = i;
			if (cnt > m[i] + 1)
				continue;
			while (cnt < m[i] + 1)
			{
				mark[add.back()] = true;
				cnt++;
				add.pop_back();
			}
		}
	}
	cnt = 0;
	for (int i = 1;i <= n;i++)
	{
		cnt += mark[i];
		ans += cnt - m[i] - 1;
	}
	cout << ans << endl;
	return 0;
}