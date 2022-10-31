#include <iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<cassert>
#include<queue>
#include<fstream>
#include<iomanip>

using namespace std;

using ll = long long;
using ull = unsigned long long;
void dfs(vector<int>& fath, int cur, vector<vector<int>>&edges)
{
	for (auto a : edges[cur])
	{
		if (fath[cur] != a)
		{
			fath[a] = cur;
			dfs(fath, a, edges);
		}
	}
}
void solve(istream& cin = std::cin, ostream& cout = std::cout)
{
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		int n;
		cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		long long ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++)
			{
				for (int h = i; h <= j; h++)
					if (v[h] == 0)
						ans += 2;
					else
						ans++;
				//cout << "HERE " << i << ' ' << j << ' ' << ans << endl;
			}
		cout << ans << '\n';
	}
}


int main()
{	
	solve();
}