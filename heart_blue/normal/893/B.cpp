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
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v;
	for (int i = 0; i < 12; i++)
	{
		int x = 1 << (i + 1);
		x--;
		v.push_back(x << i);
	}
	reverse(v.begin(), v.end());
	int x;
	cin >> x;
	for (auto &d : v)
	{
		if (x%d == 0)
		{
			cout << d << endl;
			return 0;
		}
	}
	return 0;
}