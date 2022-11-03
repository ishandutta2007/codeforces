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

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	vector<int> v1, v2;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(') v1.push_back(i + 1);
		else v2.push_back(i + 1);
	}
	reverse(v1.begin(), v1.end());
	vector<int> ans;
	while (!v1.empty() && !v2.empty() && v1.back() < v2.back())
	{
		ans.push_back(v1.back());
		ans.push_back(v2.back());
		v1.pop_back();
		v2.pop_back();
	}
	sort(ans.begin(), ans.end());
	if (ans.empty()) puts("0"), exit(0);
	puts("1");
	printf("%d\n", ans.size());
	for (auto& x : ans)
		printf("%d ", x);
	return 0;
}