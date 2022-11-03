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
const int N = 2e2 + 10;
vector<string> v[N];
int nex[N];
int flag[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	map<char, int> mc;
	MEM(nex, -1);
	while (n--)
	{
		string str;
		cin >> str;
		int o = 0;
		for (auto &c : str)
		{
			mc[c] = 1;
			if(flag[c] == 0) flag[c] = 1;
			if (o >> (c - '0') & 1)
			{
				puts("NO");
				return 0;
			}
			o |= 1 << (c - '0');
		}
		
		for (int i = 0; i + 1 < str.length(); i++)
		{
			if (nex[str[i]] == -1)
			{
				nex[str[i]] = str[i + 1];
				flag[str[i + 1]] = 2;
			}
			if (nex[str[i]] != str[i + 1])
			{
				puts("NO");
				return 0;
			}
		}
	}
	string ans;
	for (int i = 'a'; i <= 'z'; i++)
	{
		if (flag[i] != 1) continue;
		int c = i;
		while (c != -1 && ans.length() <= mc.size())
		{
			ans.push_back(c);
			c = nex[c];
		}
	}
	if (ans.length() != mc.size())
	{
		puts("NO");
	}
	else puts(ans.c_str());
	return 0;
}