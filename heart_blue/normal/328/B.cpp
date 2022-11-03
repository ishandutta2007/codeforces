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
const int N = 3e5 + 10;
int a[N];
void check(string& s, map<char, int>& mc)
{
	for (auto& c : s)
	{
		if (c == '5') c = '2';
		if (c == '9') c = '6';
		mc[c]++;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str1;
	string str2;
	map<char, int> mc1, mc2;
	cin >> str1 >> str2;
	check(str1, mc1);
	check(str2, mc2);
	int ans = INF;
	for (auto& p : mc1)
	{
		ans = min(ans, mc2[p.first] / p.second);
	}
	cout << ans << endl;
	return 0;
}