#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
//	freopen("", "rt", stdin);
//	freopen("", "wt", stdout);
	string s;
	cin >> s;
	int ans = 0;
	for (int l = 1; l < s.length(); ++l)
		for (int i = 0; i+l <= s.length(); ++i)
			for (int j = i+1; j+l <= s.length(); ++j)
			{
				bool f = true;
				for (int k = 0; k < l; ++k)
					if (s[i+k] != s[j+k]) f = false;
				if (f) ans = l;
			}
	cout << ans << '\n';
	return 0;
}