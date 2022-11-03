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
const int N = 1e6 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<string> vs = { "Danil", "Olya", "Slava", "Ann", "Nikita" };
	string str;
	cin >> str;
	map<string, int> ms;
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 1; i + j <= str.length(); j++)
		{
			ms[str.substr(i, j)]++;
		}
	}
	int tot = 0;
	for (auto &str : vs) tot += ms[str];
	if (tot == 1) puts("YES");
	else puts("NO");
	return 0;
}