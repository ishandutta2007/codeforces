#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

int n, m, str[111];
vector <int> atk, def;

int killAll()
{
	int used[111] = {0};
	
	for (int i = 0; i < int(def.size()); i++)
	{
		int found = 0;
		for (int j = 0; j < m; j++)
			if (!used[j] && str[j] > def[i])
			{
				used[j] = found = 1;
				break;
			}
		if (!found) return 0;
	}
	
	int res = 0;
	for (int i = 0; i < int(atk.size()); i++)
	{
		int found = 0;
		for (int j = 0; j < m; j++)
			if (!used[j] && str[j] >= atk[i])
			{
				used[j] = found = 1;
				res += str[j] - atk[i];
				break;
			}
		if (!found) return 0;
	}
	
	for (int i = 0; i < m; i++)
		if (!used[i]) res += str[i];
	return res;
}

int killAtk(int p)
{
	int res = 0;
	for (int i = 0; i < p; i++)
		if (str[i] >= atk[p - 1 - i]) res += str[i] - atk[p - 1 - i];
		else return 0;
	return res;
}

int main()
{
	int strJiro;
	string position;
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
	{
		cin >> position >> strJiro;
		if (position == "ATK") atk.push_back(strJiro);
		else def.push_back(strJiro);
	}
	for (int i = 0; i < m; i++) cin >> str[i];
	
	sort(atk.begin(), atk.end());
	sort(def.begin(), def.end());
	sort(str, str + m);
	int ans = killAll();
	reverse(str, str + m);
	for (int pair = 1; pair <= int(atk.size()) && pair <= m; pair++) 
		ans = max(ans, killAtk(pair));
	cout << ans << endl;
}