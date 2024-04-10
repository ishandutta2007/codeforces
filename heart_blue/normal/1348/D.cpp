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
const int N = 2e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	cin >> ncase;
	while (ncase--)
	{
		int d;
		cin >> d;
		int w = d;
		vector<int> v;
		for (int i = 0; w >> i; i++)
		{
			if (w < (1 << i)) break;
			w -= 1 << i;
			v.push_back(1 << i);
		}
		if (w)
			v.push_back(w);
		sort(v.begin(), v.end());
		printf("%d\n", v.size() - 1);
		for (int i = 1; i < v.size(); i++)
		{
			printf("%d ", v[i] - v[i - 1]);
		}
		puts("");

	}
	return 0;
}