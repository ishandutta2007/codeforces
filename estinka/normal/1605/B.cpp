#include <iostream>
#include <vector>
#include <algorithm>
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
		int n;
		cin >> n;
		string s;
		cin >> s;
		int cnt0 = count(s.begin(), s.end(), '0');
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '0' && i >= cnt0) v.push_back(i);
			if (s[i] == '1' && i < cnt0) v.push_back(i);
		}
		if (v.empty()) cout << "0\n";
		else
		{
			cout << "1\n";
			cout << v.size() << " ";
			for (int i : v) cout << i + 1 << " ";
			cout << "\n";
		}
	}
	return 0;
}