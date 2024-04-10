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
int t[200005];

vector<int> S[200005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> t[i];
	int ans = 1;
	S[0].push_back(1);
	for (int i = 1;i <= n;i++)
	{
		if (S[t[i]].size())
		{
			int to = S[t[i]].back();
			S[t[i]].pop_back();
			S[i].push_back(to);
		}
		else
		{
			int to = ++ans;
			S[i].push_back(to);
		}
	}
	cout << ans << endl;
	return 0;
}