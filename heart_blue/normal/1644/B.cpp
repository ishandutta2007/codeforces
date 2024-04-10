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
#include <valarray>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
bool check(vector<int>& v)
{
	for (int i = 2; i < v.size(); i++)
	{
		if (v[i] == v[i - 1] + v[i - 2]) return false;
	}
	for (int i = 0; i < v.size(); i++)
		printf("%d%c", v[i], " \n"[i + 1 == v.size()]);
	return true;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		vector<int> v;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			v.push_back(i + 1);
		if (v.size() > 7)
			swap(v[1], v[2]);
		do
		{
			if (check(v))
				n--;
			if (n == 0) break;
		} while (next_permutation(v.begin(), v.end()));
	}
	return 0;
}