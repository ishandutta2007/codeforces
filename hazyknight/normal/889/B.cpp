#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <fstream>

using namespace std;

int n,l,r;
int pos[26];

char ans[65];
string s[100005];

queue<int> Q;
vector<int> vol[26];
vector<string> final_ans;

bool vis[26];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i];
		for (int j = 0;j < s[i].size();j++)
		{
			if (vol[s[i][j] - 'a'].size() && vol[s[i][j] - 'a'].back() == i)
			{
				cout << "NO" << endl;
				return 0; 
			}
			vol[s[i][j] - 'a'].push_back(i);
		}
	}
	for (int c = 0;c < 26;c++)
	{
		if (vis[c] || !vol[c].size())
			continue;
		for (int i = 0;i < 65;i++)
			ans[i] = ' ';
		l = 30,r = 30;
		ans[30] = char(c + 'a');
		pos[c] = l;
		Q.push(c);
		vis[c] = true;
		while (!Q.empty())
		{
			int now = Q.front();
			Q.pop();
			for (int i = 0;i < vol[now].size();i++)
			{
				string tmp = s[vol[now][i]];
				int p = 0;
				for (int j = 0;j < tmp.size();j++)
					if (tmp[j] == 'a' + now)
					{
						p = j;
						break;
					}
				for (int j = pos[now] - 1,k = p - 1;k >= 0;l = min(l,j),j--,k--)
				{
					if (ans[j] != ' ' && ans[j] != tmp[k])
					{
						cout << "NO" << endl;
						return 0;
					}
					ans[j] = tmp[k];
					if (pos[ans[j] - 'a'] && pos[ans[j] - 'a'] != j)
					{
						cout << "NO" << endl;
						return 0;
					}
					pos[ans[j] - 'a'] = j;
				}
				for (int j = pos[now] + 1,k = p + 1;k < tmp.size();r = max(r,j),j++,k++)
				{
					if (ans[j] != ' ' && ans[j] != tmp[k])
					{
						cout << "NO" << endl;
						return 0;
					}
					ans[j] = tmp[k];
					if (pos[ans[j] - 'a'] && pos[ans[j] - 'a'] != j)
					{
						cout << "NO" << endl;
						return 0;
					}
					pos[ans[j] - 'a'] = j;
				}
			}
			for (int i = l;i <= r;i++)
				if (!vis[ans[i] - 'a'])
				{
					vis[ans[i] - 'a'] = true;
					Q.push(ans[i] - 'a');
				}
		}
		string input;
		for (int i = l;i <= r;i++)
			input += ans[i];
		final_ans.push_back(input);
	}
	sort(final_ans.begin(),final_ans.end());
	for (int i = 0;i < final_ans.size();i++)
		cout << final_ans[i];
	cout << endl;
	return 0;
}