#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <iomanip>
typedef long long ll;
using namespace std;

bool cmp2(char a, char b)
{
	if (a == 'b' && b == 'c') return false;
	if (a == 'c' && b == 'b') return true;
	return a < b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		string s, t;
		cin >> s >> t;
		if (t != "abc" || !count(s.begin(), s.end(), 'a'))
		{
			sort(s.begin(), s.end());
		}
		else
		{
			sort(s.begin(), s.end(), cmp2);
		}
		cout << s << "\n";
	}
	return 0;
}