#include <bits/stdc++.h>

using namespace std;

int T,n;

string s,t;

int main()
{
	cin >> T;
	while (T--)
	{
		string s,t;
		cin >> s >> t;
		bool ok = 0;
		for (int i = 0;i < s.size();i++)
		{
			string res = s.substr(0,i + 1),a = s.substr(0,i);
			reverse(a.begin(),a.end());
			res += a;
			if (res.find(t) != res.npos)
			{
				ok = 1;
				break;
			}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}