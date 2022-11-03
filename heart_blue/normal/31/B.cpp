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
#define MEM(x, y) memset((x),(y),sizeof(x))
const int INF = 1e9 + 7;
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	vector<int> v;
	if (str.front() == '@' || str.back() == '@')
	{
		cout << "No solution" << endl;
		return 0;
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '@') v.push_back(i);
	}
	if (v.empty())
	{
		cout << "No solution" << endl;
		return 0;
	}
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] - v[i - 1] <= 2)
		{
			cout << "No solution" << endl;
			return 0;
		}
	}
	int cnt = 0;
	for (int i = 0; i < str.length(); i++)
	{
		cout << str[i];
		if (str[i] == '@')
		{
			cnt++;
			cout << str[i + 1];
			if (cnt != v.size()) cout << ',';
			i++;
		}
	}
	return 0;
}