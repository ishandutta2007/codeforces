#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e2 + 10;
int flag[N];
int key = -1;
int getcnt()
{
	int cnt = 0;
	for (int i = 'a'; i <= 'z'; i++) cnt += flag[i];
	if (cnt == 1)
	{
		for (int i = 'a'; i <= 'z'; i++)
		{
			if (flag[i] == 1) key = i;
		}
	}
	return cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	map<int, int> s;
	for (int i = 'a'; i <= 'z'; i++) s[i] = 1;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		char c;
		string str;
		cin >> c >> str;
		if (c == '.')
		{
			for (auto &c : str) if (s.count(c)) s.erase(c);
		}
		else if (c == '!')
		{
			if (s.size() == 1) ans++;
			int f[N];
			MEM(f, 0);
			for (auto &c : str) f[c] = 1;
			for (int i = 'a'; i <= 'z'; i++)
			{
				if (f[i] == 0 && s.count(i))
				{
					s.erase(i);
				}
			}
		}
		else
		{
			if (s.size() > 1)
			{
				if (s.count(str[0])) s.erase(str[0]);
				continue;
			}
			if (s.begin()->first == str[0]) break;
			else ans++;
		}
	}
	cout << ans << endl;
	return 0;
}