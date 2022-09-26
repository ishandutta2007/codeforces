#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector> 

using namespace std;

int n;
int s[105];
int cnt[105];

char res[105];

vector<int> t1,t2,t3;
vector<int> pos[105];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> s[i],pos[s[i]].push_back(i),cnt[s[i]]++;
	for (int i = 1;i <= 100;i++)
	{
		if (cnt[i] == 1)
			t1.push_back(i);
		if (cnt[i] == 2)
			t2.push_back(i);
		if (cnt[i] > 2)
			t3.push_back(i);
	}
	if (!t3.size() && (t1.size() & 1))
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for (int i = 1;i <= n;i++)
		res[i] = 'A';
	for (int i = 0;i < t1.size();i++)
	{
		if (i & 1)
			res[pos[t1[i]][0]] = 'B';
	}
	if (t1.size() & 1)
		res[pos[t3[0]][0]] = 'B';
	for (int i = 1;i <= n;i++)
		cout << res[i];
	cout << endl;
	return 0;
}