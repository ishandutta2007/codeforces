#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <iomanip>
#include <cmath>
typedef long long ll;
using namespace std;

const int maxn = 5e5 + 5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	vector<vector<int> > v(q, vector<int>(1));
	for (int i = 0; i < q; i++)
	{
		cin >> v[i][0];
		v[i].resize(v[i][0] + 1);
		for (int j = 0; j < v[i][0]; j++)
		{
			cin >> v[i][j + 1];
		}
	}
	vector<int> col(maxn, 0);
	for (int i = 0; i < maxn; i++) col[i] = i;
	vector<int> ans;
	for (int i = q - 1; i >= 0; i--)
	{
		if (v[i][0] == 1)
		{
			ans.push_back(col[v[i][1]]);
		}
		else
		{
			col[v[i][1]] = col[v[i][2]];
		}
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}