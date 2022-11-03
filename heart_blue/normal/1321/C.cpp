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
	int n;
	cin >> n;
	string str;
	cin >> str;
	for (int o = 0; o <= 200; o++)
	{
		for (char cc = 'z'; cc >= 'a'; cc--)
		{
			int cur = str.length();
			string s;
			for (int i = 0; i < str.length(); i++)
			{
				int flag = 0;
				if (str[i] == cc)
				{
					if (i > 0 && str[i] - 1 == str[i - 1]) flag = 1;
					if (i + 1 < str.length() && str[i] - 1 == str[i + 1]) flag = 1;
				}
				if (flag == 0) s.push_back(str[i]);
			}
			str = s;
			if (cur != str.length()) break;
		}
	}
	cout << n - str.length() << endl;
	return 0;
}