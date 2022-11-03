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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int x[N], y[N];
vector<string> vs;
bool check(string &str)
{
	for (int i = 1; i < str.length(); i++)
	{
		char c1 = str[i - 1], c2 = str[i];
		if (abs(x[c1] - x[c2]) > 1 || abs(y[c1] - y[c2]) > 1) return false;
	}
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	map<char, int> mc;
	string s;
	vs.resize(2);
	for (int i = 0; i < str.length(); i++)
	{
		mc[str[i]]++;
		if (i > 0)
		{
			if (str[i] == str[i - 1])
			{
				puts("Impossible");
				return 0;
			}
		}
		if (mc[str[i]] > 1)
		{
			s = str.substr(0, i) + str.substr(i + 1);
			break;
		}
	}
	int o = 26;
	while(o--)
	{
		vs[0] = s.substr(0, 13);
		vs[1] = s.substr(13);
		reverse(vs[1].begin(), vs[1].end());
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				x[vs[i][j]] = i;
				y[vs[i][j]] = j;
			}
		}
		if (check(str))
		{
			cout << vs[0] << endl;
			cout << vs[1] << endl;
			return 0;
		}
		s = s.substr(1) + s.substr(0, 1);
	}
	puts("Impossible");
	return 0;
}