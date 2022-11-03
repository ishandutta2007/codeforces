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
const int M = 1e5;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		cout << string(4, i + '0') << endl;
		int x, y;
		cin >> x >> y;
		if (x == 4)
		{
			return 0;
		}
		while (x--) v.push_back(i);
	}
	sort(v.begin(), v.end());
	while (1)
	{
		for (auto &x : v) cout << x;
		cout << endl;
		int x, y;
		cin >> x >> y;
		if (x == 4) return 0;
		next_permutation(v.begin(), v.end());
	}
	return 0;
}