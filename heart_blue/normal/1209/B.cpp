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
const int N = 1e5 + 10;
int sum[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string str;
	cin >> str;
	int ans = 0;
	for (auto& c : str)
	{
		int x = c - '0';
		int a, b;
		cin >> a >> b;
		for (int i = 0; i < N; i++)
		{
			if (i >= b && (i - b) % a == 0) x ^= 1;
			sum[i] += x;
			ans = max(ans, sum[i]);
		}
		ans = ans;
	}
	cout << ans << endl;
	return 0;
}