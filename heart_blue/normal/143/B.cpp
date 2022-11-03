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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int flag = 0;
	if (str.front() == '-') str = str.substr(1), flag = 1;
	string s1, s2;
	if (str.find('.') != -1)
	{
		int o = str.find('.');
		s1 = str.substr(0, o);
		s2 = str.substr(o);
		while (s2.length() > 3) s2.pop_back();
		while (s2.length() < 3) s2 += '0';
	}
	else
	{
		s1 = str;
		s2 = ".00";
	}
	if (flag) cout << "(";
	cout << "$";
	while (s1.length() % 3) s1 = "0" + s1;
	for (int i = 0; i < s1.length(); i+=3)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 0 && j < 2 && s1[i + j] == '0') continue;
			cout << s1[i + j];
		}
		if (i + 3 != s1.length()) cout << ',';
	}
	cout << s2;
	if (flag) cout << ")";
	return 0;
}