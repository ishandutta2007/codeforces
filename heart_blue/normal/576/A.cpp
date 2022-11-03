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
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(a, 0);
	for (int i = 2; i < N; i++)
	{
		if (a[i]) continue;
		for (int j = i*i; j < N; j += i) a[j] = 1;
	}
	int n;
	cin >> n;
	vector<int> ans;
	for (int i = 2; i <= n; i++)
	{
		if (a[i]) continue;

		int t = i;
		while (n >= t)
		{
			ans.push_back(t);
			t *= i;
		}
	}
	cout << ans.size() << endl;
	for (auto &x : ans)
	{
		cout << x << ' ';
	}
	return 0;
}