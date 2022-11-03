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
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e4 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for (auto &x : v) scanf("%d", &x);
	sort(v.begin(), v.end());
	if (v.size() == 1)
	{
		cout << v[0] << '\n';
		return 0;
	}
	if (v.size() == 2)
	{
		cout << v[1] - v[0] << '\n';
		return 0;
	}
	if (v.front() <= 0)
	{
		LL sum = v.back();
		for (int i = 0; i + 1 < v.size(); i++)
		{
			sum += abs(v[i]);
		}
		printf("%lld\n", sum);
		return 0;
	}
	v.front() = -v.front();
	LL sum = 0;
	for (auto &x : v) sum += x;
	printf("%lld\n", sum);
	return 0;
}