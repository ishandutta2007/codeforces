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
const int N = 5e3 + 10;

bool check(const string& str)
{
	return count(str.begin(), str.end(), '0') != count(str.begin(), str.end(), '1');
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string str;
	cin >> n >> str;
	if (check(str))
	{
		puts("1");
		puts(str.c_str());
		return 0;
	}
	for (int i = 1; i < str.length(); i++)
	{
		if (check(str.substr(0, i)) && check(str.substr(i)))
		{
			puts("2");
			cout << str.substr(0, i) << ' ' << str.substr(i) << endl;
			break;
		}
	}
	return 0;
}