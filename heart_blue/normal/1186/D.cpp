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
	vector<int> v1, v2;
	LL sum = 0;
	int n;
	cin >> n;
	while (n--)
	{
		int x, y;
		string str;
		cin >> str;
		int o = str[0];
		sscanf(str.c_str(), "%d.%d", &x, &y);
		if (y != 0)
		{
			if (o != '-') x++;
		}
		v1.push_back(x);
		v2.push_back(y);
		sum += x;
	}
	for (int i = 0; i < v1.size() && sum > 0; i++)
	{
		if (v2[i] == 0) continue;
		v1[i] --;
		sum--;
	}
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << '\n';
	return 0;
}