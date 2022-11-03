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
const LL INF = 1e9 + 1;
const int N = 2e6;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);
	map<int, int> m;
	int a, b;
	int n;
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		m[a] = b;
	}
	for (auto &it : m)
	{
		int x = it.first + it.second;
		if (!m.count(x)) continue;
		auto it1 = m.find(x);
		if (x + it1->second == it.first)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}