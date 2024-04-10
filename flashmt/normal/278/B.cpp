#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

set <string> has;
string ans = "zzz";

void go(int length, string s)
{
	if (length == 3) return;
	if (length && !has.count(s))
	{
		if (length < ans.size()) ans = s;
		else ans = min(ans, s);
		return;
	}
	for (char c = 'a'; c <= 'z'; c++) go(length + 1, s + c);
}

int main()
{
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < int(s.size()); j++)
			for (int k = 1; j + k <= int(s.size()); k++)
				has.insert(s.substr(j, k));
	}
	go(0, "");
	cout << ans << endl;
}