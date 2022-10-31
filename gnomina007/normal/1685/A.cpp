#include <iostream>
#include<vector>
#include<fstream>
#include<set>
#include<random>
#include<queue>
#include<algorithm>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int main()
{
	int test;
	cin >> test;
	for (int tt = 0; tt < test; tt++)
	{
		int n;
		cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		if (n % 2 == 1)
			cout << "NO" << endl;
		else
		{
			sort(v.begin(), v.end());
			vector<int>ans;
			int cur = 0;
			for (int i = 0; i < n; i++)
			{
				ans.push_back(v[cur]);
				if (cur < n/2)
					cur += n/2;
				else
					cur -= n/2 - 1;
			}
			int lose = 0;
			for (int i = 0; i < n - 1; i++)
			{
				if (i % 2 == 0 && ans[i] >= ans[i + 1])
					lose = 1;
				if (i % 2 == 1 && ans[i] <= ans[i + 1])
					lose = 1;
			}
			if (lose)
				cout << "NO" << endl;
			else
			{
				cout << "YES \n";
				for (auto a : ans)
					cout << a << ' ';
				cout << endl;
			}
		}
	}
}