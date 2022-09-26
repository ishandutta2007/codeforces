#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <cmath> 

using namespace std;

string s;

vector<int> pos[3];

int main()
{
	cin >> s;
	for (int i = 0;i < s.size();i++)
		pos[s[i] - '0'].push_back(i);
	for (int i = 0;i < 3;i++)
		reverse(pos[i].begin(),pos[i].end());
	for (int i = 0;i < s.size();i++)
	{
		if (pos[0].size() > 0)
		{
			if (!pos[2].size() || pos[2].back() > pos[0].back())
			{
				cout << 0;
				pos[0].pop_back();
				continue;
			}
		}
		if (pos[1].size() > 0)
		{
			cout << 1;
			pos[1].pop_back();
			continue;
		}
		cout << 2;
		pos[2].pop_back();
	}
	cout << endl;
	return 0;
}