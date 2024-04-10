#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <queue>
typedef long long ll;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, a, b;
		cin >> n >> a >> b;
		set<int> s;
		vector<int> h1, h2;
		for (int i = 1; i <= n; i++) s.insert(i);
		h1.push_back(a);
		s.erase(a);
		h2.push_back(b);
		s.erase(b);
		for (int i = 0; i < n / 2 - 1; i++)
		{
			int x = *prev(s.end());
			h1.push_back(x);
			s.erase(x);
		}
		for (int i : s)
		{
			h2.push_back(i);
		}
		if (*min_element(h1.begin(), h1.end()) != a || *max_element(h2.begin(), h2.end()) != b)
		{
			cout << "-1\n";
		}
		else
		{
			for (int i : h1) cout << i << " ";
			for (int i : h2) cout << i << " ";
			cout << "\n";
		}
	}
	return 0;
}