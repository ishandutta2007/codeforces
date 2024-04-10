#include<bits/stdc++.h>

using namespace std;

int n, k;

bool decimalLess(const string& s, const string& t)
{
	if(s.size() != t.size())
		return s.size() < t.size();
	for(int i = 0; i < s.size(); i++)
		if(s[i] != t[i])
			return s[i] < t[i];
	return false;
}

void upd(string& ans, const string& cur)
{
	if(ans == "-1" || decimalLess(cur, ans))
		ans = cur;
}

void read()
{
	cin >> n >> k;
}

void solve()
{
	string ans = "-1";
	for(int i = 0; i <= 9; i++)
	{
		int cnt9 = n / 9;
		if(i + k < 10)
			cnt9 = 0;
		for(int j = 0; j <= cnt9; j++)
		{
		    if(i + k >= 10 && j == 0)
		        continue;
			int curSum = (i + (i + k)) * (k + 1) / 2;
			if(j != 0)
			{
				int cntBefore = 10 - i;
				int cntAfter = k + 1 - cntBefore;
				curSum = (i + 9) * cntBefore / 2 + cntBefore * 9 * (j - 1) + (1 + cntAfter) * cntAfter / 2;
			}
			curSum = n - curSum;
			if(curSum < 0 || curSum % (k + 1) != 0)
				continue;
			string curNum = {char('0' + i)};
			for(int z = 0; z < j - 1; z++)
				curNum += "9";
			int maxNum = 9;
			if(i + k >= 10)
				maxNum = 8;
			curSum /= (k + 1);
			while(curSum != 0)
			{
				int d = min(curSum, maxNum);
				maxNum = 9;
				curSum -= d;
				curNum.push_back(char('0' + d));
			}
			reverse(curNum.begin(), curNum.end());
			upd(ans, curNum);
		}
	}
	cout << ans << endl;
}

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		read();
		solve();
	}
}