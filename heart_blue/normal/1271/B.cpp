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
void output(string &str, vector<int>& v)
{
	if (count(str.begin(), str.end(), 'W') % str.length() != 0) return;
	printf("%d\n", v.size());
	for (auto& x : v) cout << x << ' ';
	exit(0);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int val = 'B' ^ 'W';
	int n;
	string str;
	cin >> n >> str;
	vector<int> ans;
	for (int i = 0; i + 1 < n; i++)
	{
		if (str[i] != 'W') ans.push_back(i + 1), str[i] ^= val, str[i + 1] ^= val;
	}
	output(str, ans);
	for (int i = 0; i + 1 < n; i++)
	{
		if (str[i] != 'B') ans.push_back(i + 1), str[i] ^= val, str[i + 1] ^= val;
	}
	output(str, ans);
	puts("-1");
	return 0;
}