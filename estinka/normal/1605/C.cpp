#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

bool is_substr(const string& s, string t)
{
	for (int i = 0; i + t.size() <= s.size(); i++)
	{
		bool ok = true;
		for (int j = i; j < i + t.size(); j++) if (s[j] != t[j - i])
		{
			ok = false;
			break;
		}
		if (ok) return true;
	}
	return false;
}
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
		if (is_substr(s, "aa")) cout << "2\n";
		else if (is_substr(s, "aba")) cout << "3\n";
		else if (is_substr(s, "aca")) cout << "3\n";
		else if (is_substr(s, "abca")) cout << "4\n";
		else if (is_substr(s, "acba")) cout << "4\n";
		else if (is_substr(s, "abbacca")) cout << "7\n";
		else if (is_substr(s, "accabba")) cout << "7\n";
		else cout << "-1\n";
	}
	return 0;
}