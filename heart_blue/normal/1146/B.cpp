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
const int N = 50 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	string s;
	cin >> str;
	for (auto &c : str)
	{
		if (c != 'a')
			s.push_back(c);
	}
	if (s.length() & 1)
	{
		puts(":(");
		return 0;
	}
	string s1 = s.substr(0, s.length() / 2);
	string s2 = s.substr(s.length() / 2);
	string s3 = str.substr(str.length() - s1.length());
	if (s1 == s2 && s1 == s3) puts(str.substr(0, str.length() - s1.length()).c_str());
	else puts(":(");
	return 0;
}