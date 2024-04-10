#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

int n;
int b[10005];

string s,t,ans,res,ask[3];

vector<int> pos[3][26];

int main()
{
	cin >> t;
	n = t.size();
	res = ans = ask[0] = ask[1] = ask[2] = t;
	int len0 = (n + 25) / 26;
	for (int i = 0;i < n;i++)
		ask[0][i] = 'a' + i / len0;
	cout << "? " << ask[0] << endl;
	cout.flush();
	cin >> res;
	for (int i = 0;i < res.size();i++)
		pos[0][res[i] - 'a'].push_back(i);
	
	int len1 = (len0 + 25) / 26;
	for (int i = 0;i < n;i++)
		ask[1][i] = 'a' + i % len0 / len1;
	cout << "? " << ask[1] << endl;
	cout.flush();
	cin >> res;
	for (int i = 0;i < res.size();i++)
		pos[1][res[i] - 'a'].push_back(i);
	
	int len2 = (len1 + 25) / 26;
	for (int i = 0;i < n;i++)
		ask[2][i] = 'a' + i % len0 % len1 / len2;
	cout << "? " << ask[2] << endl;
	cout.flush();
	cin >> res;
	for (int i = 0;i < res.size();i++)
		pos[2][res[i] - 'a'].push_back(i);
	
	for (int i = 0;i < n;i++)
	{
		int p0 = 0,p1 = 0,p2 = 0;
		bool flag = 0;
		vector<int> &pos0 = pos[0][ask[0][i] - 'a'],&pos1 = pos[1][ask[1][i] - 'a'],&pos2 = pos[2][ask[2][i] - 'a'];
		while (p0 < pos0.size() && p1 < pos1.size() && p2 < pos2.size())
		{
			if (pos0[p0] == pos1[p1] && pos1[p1] == pos2[p2])
			{
				ans[i] = t[pos0[p0]];
				break;
			}
			if (pos0[p0] <= pos1[p1] && pos0[p0] <= pos2[p2])
				p0++;
			else if (pos1[p1] <= pos0[p0] && pos1[p1] <= pos2[p2])
				p1++;
			else
				p2++;
		}
	}
	cout << "! " << ans << endl;
	return 0;
}