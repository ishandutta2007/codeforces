#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <string> names;
int points[2000] = {0}, champ[2000][50] = {0};

int prize[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

int get_num(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (s == names[i]) return i;
	names.push_back(s);
	return names.size() - 1;
}

bool cmp1(int i, int j)
{
	if (points[i] != points[j]) return points[i] > points[j];
	for (int k = 0; k < 50; ++k)
		if (champ[i][k] != champ[j][k]) return champ[i][k] > champ[j][k];
	return false;
}

bool cmp2(int i, int j)
{
	if (champ[i][0] != champ[j][0]) return champ[i][0] > champ[j][0];
	if (points[i] != points[j]) return points[i] > points[j];
	for (int k = 1; k < 50; ++k)
		if (champ[i][k] != champ[j][k]) return champ[i][k] > champ[j][k];
	return false;
}


int main()
{
//	freopen("in", "rt", stdin);
//	freopen("out", "wt", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		for (int j = 0; j < t; ++j)
		{
			string s;
			cin >> s;
			int num = get_num(s);
			champ[num][j]++;
			if (j < 10) points[num] += prize[j];
		}
	}
	int w1 = 0, w2 = 0;
	for (int i = 1; i < names.size(); ++i)
	{
		if (cmp1(i, w1)) w1 = i;
		if (cmp2(i, w2)) w2 = i;
	}
	cout << names[w1] << '\n' << names[w2] << '\n';
	return 0;
}