#include <bits/stdc++.h>

using namespace std;

string s;

int ans;

int main()
{
	cin >> s;
	for (int i = 0;i <= 99999999;i += 25)
	{
		string t;
		if (i == 0)
			t = "0";
		else
		{
			int I = i;
			while (I)
			{
				t += char('0' + I % 10);
				I /= 10;
			}
			reverse(t.begin(),t.end());
		}
		if (t.size() != s.size())
			continue;
		int X = -1;
		bool ok = 1;
		for (int j = 0;ok && j < s.size();j++)
		{
			if (s[j] == '_')
				continue;
			if (s[j] == 'X')
			{
				if (X == -1)
					X = t[j] - '0';
				else if (X != t[j] - '0')
					ok = 0;
				continue;
			}
			if (t[j] != s[j])
				ok = 0;
		}
		ans += ok;
	}
	printf("%d\n",ans);
	return 0;
}