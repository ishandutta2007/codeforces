#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int n, par[100100], pre[300300];
string str[100100], pattern;
vector <int> a[100100];
long long ans;

void preKMP()
{
	pre[0] = -1;
	for (int i = 0, j = -1; i < int(pattern.size()); )
	{
		while (j >= 0 && pattern[i] != pattern[j]) j = pre[j];
		i++; j++;
		pre[i] = (j == n || pattern[i] == pattern[j] ? pre[j] : j);
	}
}

void visit(int x, int match)
{
	for (int i = 0; i < int(a[x].size()); i++)
	{
		int y = a[x][i], newMatch = match;
		for (int j = 0; j < int(str[y].size()); j++)
		{
			while (newMatch >= 0 && str[y][j] != pattern[newMatch]) newMatch = pre[newMatch];
			++newMatch;
			if (newMatch == pattern.size()) ans++, newMatch = pre[newMatch];
		}
		visit(y, newMatch);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 2; i <= n; i++) cin >> par[i] >> str[i], a[par[i]].push_back(i);
	cin >> pattern;
	
	preKMP();
	visit(1, 0);
	cout << ans << endl;
}