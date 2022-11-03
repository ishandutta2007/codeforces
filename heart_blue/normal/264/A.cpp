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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v1, v2;
	int n;
	string str;
	cin >> str;
	n = str.length();
	for (int i = 1; i <= n; i++)
	{
		char c = str[i - 1];
		if (c == 'l') v1.push_back(i);
		else v2.push_back(i);
	}
	if (v1.size()) reverse(v1.begin(), v1.end());
	for (auto &x : v2) cout << x << '\n';
	for (auto &x : v1) cout << x << '\n';
	return 0;
}