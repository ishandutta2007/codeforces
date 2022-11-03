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
const int N = 2e5 + 10;
map<string, int> ms;
vector<string> vs;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		vs.push_back(str);
		ms[str] = 1;
	}
	int sum = 'S' ^ 'E' ^ 'T';
	LL ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			string s;
			for (int t = 0; t < k; t++)
			{
				if (vs[i][t] == vs[j][t]) s.push_back(vs[i][t]);
				else s.push_back(vs[i][t] ^ vs[j][t] ^ sum);
			}
			ans += ms.count(s);
		}
	}
	cout << ans / 3 << endl;
	return 0;
}