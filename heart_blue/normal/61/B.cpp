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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
void refrain(string &str)
{
	string ret;
	for (auto &c : str)
	{
		if (isalpha(c)) ret.push_back(tolower(c));
	}
	str = ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<string> vs(3);
	for (auto &str : vs)
	{
		cin >> str;
		refrain(str);
	}
	sort(vs.begin(), vs.end());
	map<string, int> ms;
	do
	{
		string str = vs[0] + vs[1] + vs[2];
		ms[str] = 1;
	} while (next_permutation(vs.begin(), vs.end()));
	int q;
	cin >> q;
	while (q--)
	{
		string str;
		cin >> str;
		refrain(str);
		if (ms.count(str)) puts("ACC");
		else puts("WA");
	}
	return 0;
}