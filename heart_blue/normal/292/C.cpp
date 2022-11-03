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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
vector<int> key;
vector<string> vs;
vector<string> ans;
void build(string& str, int l, int r, int o = 0)
{
	if (l > r)
	{
		if (o == (1 << key.size()) - 1)
			vs.push_back(str);
		return;
	}
	for (int i = 0; i < key.size(); i++)
	{
		str[l] = str[r] = key[i] + '0';
		build(str, l + 1, r - 1, 1 << i | o);
	}
}
bool isok(string& str)
{
	if (str.length() == 1) return true;
	if (str.length() > 3) return false;
	if (str[0] == '0') return false;
	int x = stoi(str);
	return x >= 0 && x <= 255;
}
void check(string& str)
{
	string s1, s2, s3, s4;
	int n = str.length();
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k + 1 < n; k++)
			{
				s1 = str.substr(0, i + 1);
				s2 = str.substr(i + 1, j - i);
				s3 = str.substr(j + 1, k - j);
				s4 = str.substr(k + 1);
				if (isok(s1) && isok(s2) && isok(s3) && isok(s4))
				{
					ans.push_back(s1 + '.' + s2 + '.' + s3 + '.' + s4);
				}
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	key.resize(n);
	for (auto& x : key)
		scanf("%d", &x);
	for (int i = 4; i <= 12; i++)
	{
		string str(i, '0');
		build(str, 0, i - 1);
	}
	for (auto& s : vs)
	{
		check(s);
	}
	printf("%d\n", ans.size());
	for (auto& s : ans)
		puts(s.c_str());
	return 0;
}