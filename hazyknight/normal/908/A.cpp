#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>

using namespace std;

int main()
{
	string s;
	int ans = 0;
	cin >> s;
	for (int i = 0;i < s.size();i++)
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			ans++;
		else if (s[i] >= '0' && s[i] <= '9' && (s[i] - '0') % 2 == 1)
			ans++;
	cout << ans << endl;
	return 0;
}