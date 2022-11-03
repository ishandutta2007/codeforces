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
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int a[24][6] =
{
	0, 1, 2, 3, 4, 5,
	0, 2, 3, 4, 1, 5,
	0, 3, 4, 1, 2, 5,
	0, 4, 1, 2, 3, 5,
	1, 0, 4, 5, 2, 3,
	1, 4, 5, 2, 0, 3,
	1, 5, 2, 0, 4, 3,
	1, 2, 0, 4, 5, 3,
	2, 0, 1, 5, 3, 4,
	2, 1, 5, 3, 0, 4,
	2, 5, 3, 0, 1, 4,
	2, 3, 0, 1, 5, 4,
	3, 0, 2, 5, 4, 1,
	3, 2, 5, 4, 0, 1,
	3, 5, 4, 0, 2, 1,
	3, 4, 0, 2, 5, 1,
	4, 0, 3, 5, 1, 2,
	4, 3, 5, 1, 0, 2,
	4, 5, 1, 0, 3, 2,
	4, 1, 0, 3, 5, 2,
	5, 2, 1, 4, 3, 0,
	5, 1, 4, 3, 2, 0,
	5, 4, 3, 2, 1, 0,
	5, 3, 2, 1, 4, 0
};
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	map<string, int> ms;
	sort(s.begin(), s.end());
	int ans = 0;
	do
	{
		if (ms.count(s))
		{
			continue;
		}
		ans++;
		for (int i = 0; i < 24; i++)
		{
			string str;
			for (int j = 0; j < 6; j++) str += s[a[i][j]];
			ms[str] = 1;
		}
	} while (next_permutation(s.begin(), s.end()));
	cout << ans << endl;
	return 0;
}