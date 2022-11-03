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
const int N = 1e2 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		string str;
		map<char, int> mc;
		cin >> str;
		str.push_back('*');
		int cnt = 1;
		for (int i = 1; i < str.length(); i++)
		{
			if (str[i] == str[i - 1]) cnt++;
			else
			{
				if (cnt & 1) mc[str[i - 1]] = 1;
				cnt = 1;
			}
		}
		for (auto& p : mc) putchar(p.first);
		puts("");
	}
	return 0;
}