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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e1 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		string str;
		cin >> str;
		string s;
		map<char, int> mc;
		for (auto& c : str)
		{
			mc[c]++;
		}
		for (auto& p : mc)
		{
			s.push_back(p.first);
		}
		int cnt = 100;
		int flag = 0;
		while (cnt--)
		{
			random_shuffle(s.begin(), s.end());
			flag = 1;
			for (int i = 0; i + 1 < s.length(); i++)
			{
				if (abs(s[i] - s[i + 1]) == 1)
				{
					flag = 0;
					break;
				}
			}
			if (flag) break;
		}
		if (flag == 0)
		{
			cout << "No answer" << endl;
			continue;
		}
		for (auto& c : s)
		{
			cout << string(mc[c], c);
		}
		cout << endl;
	}
	return 0;
}