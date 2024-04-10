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
const int N = 1e6 + 10;
vector<string> vs;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vs.resize(n);
	for (auto &str : vs) cin >> str;
	for (int i = n - 1; i > 0; i--)
	{
		string &s1 = vs[i - 1];
		string &s2 = vs[i];
		if (s1 <= s2) continue;
		int k = 0;
		int m = min(s1.length(), s2.length());
		for (k = 0; k < m; k++)
		{
			if (s1[k] != s2[k]) break;
		}
		s1 = s1.substr(0, k);
	}
	for (auto &str : vs) puts(str.c_str());
	return 0;
}