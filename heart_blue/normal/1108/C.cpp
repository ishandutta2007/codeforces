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
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
int check(string &s1, string &s2)
{
	int tot = 0;
	for (int i = 0; i < s1.length(); i++)
	{
		tot += s1[i] != s2[i];
	}
	return tot;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	int n;
	cin >> n;
	cin >> str;
	string ans = str;
	string rgb = "BGR";
	pair<int, string> res = { INF,"" };
	do
	{
		for (int i = 0; i < str.length(); i++)
		{
			ans[i] = rgb[i % 3];
		}
		res = min(res, { check(str,ans),ans });


	} while (next_permutation(rgb.begin(), rgb.end()));
	printf("%d\n%s\n", res.first, res.second.c_str());
	return 0;
}