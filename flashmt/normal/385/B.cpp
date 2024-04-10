#include <bits/stdc++.h>
using namespace std;

int rightmost[5555], ans;

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < int(s.size()); i++)
	{
		if (i) rightmost[i] = max(rightmost[i], rightmost[i - 1]);
		if (i + 4 <= int(s.size()) && s.substr(i, 4) == "bear")
			rightmost[i + 3] = max(rightmost[i + 3], i + 1);
	}
	
	for (int i = 0; i < int(s.size()); i++) ans += rightmost[i];
	cout << ans << endl;
}