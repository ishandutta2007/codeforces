#include <bits/stdc++.h> 

using namespace std;

string s;

vector<string> b[5005];

int cnt[26];
long double ans;

int main()
{
	ios::sync_with_stdio(false);
	cin >> s;
	for (int i = 0;i < s.size();i++)
	{
		string t;
		for (int j = i;j < s.size();j++)
			t += s[j];
		for (int j = 0;j < i;j++)
			t += s[j];
		b[s[i] - 'a'].push_back(t);
	}
	for (int i = 0;i < 26;i++)
	{
		long double MAX = 0;
		for (int j = 1;j < s.size();j++)
		{
			memset(cnt,0,sizeof(cnt));
			for (int k = 0;k < b[i].size();k++)
				cnt[b[i][k][j] - 'a']++;
			long double cur = 0;
			for (int k = 0;k < 26;k++)
				cur += (cnt[k] == 1);
			MAX = max(MAX,cur);
		}
		ans += MAX / (double)s.size();
	}
	printf("%.10lf\n",(double)ans);
	return 0;
}