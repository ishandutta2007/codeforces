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
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> v2;
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		cin >> v[i];
		if (v[i] >= 0) sum += (v[i] / 2);
		else sum += (v[i] - 1) / 2;
		if (v[i] % 2 == 0)
		{
			v[i] /= 2;
			continue;
		}
		if (v[i] >= 0) v[i] /= 2;
		else v[i] = (v[i] - 1) / 2;
		v2.push_back(i);
	}
	while (sum < 0)
	{
		sum++;
		v[v2.back()]++;
		v2.pop_back();
	}
	for (auto& x : v)
		printf("%d\n", x);
	return 0;
}