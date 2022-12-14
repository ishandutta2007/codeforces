#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
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
		int x1, p1, x2, p2;
		cin >> x1 >> p1 >> x2 >> p2;
		string s1 = to_string(x1);
		string s2 = to_string(x2);
		if (s1.size() + p1 < s2.size() + p2)
		{
			cout << "<\n";
			continue;
		}
		if (s1.size() + p1 > s2.size() + p2)
		{
			cout << ">\n";
			continue;
		}
		while (s1.size() < s2.size()) s1.push_back('0');
		while (s1.size() > s2.size()) s2.push_back('0');
		x1 = stoi(s1), x2 = stoi(s2);
		if (x1 < x2) cout << "<\n";
		else if (x1 == x2) cout << "=\n";
		else cout << ">\n";
	}
	return 0;
}