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
const int N = 5e5 + 10;
int a[N];
int mod;
vector<int>& check(int a[], int n)
{
	vector<int> *v = new vector<int>();
	for (int i = 0; i < (1 << n); i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (i >> j & 1)
			{
				sum += a[j];
				if (sum >= mod) sum -= mod;
			}
		}
		v->push_back(sum);
	}
	sort(v->begin(), v->end());
	return *v;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n >> mod;
	for (int i = 0; i < n; i++) cin >> a[i], a[i] %= mod;
	vector<int> &v1 = check(a, n / 2);
	vector<int> &v2 = check(a + n / 2, n - n / 2);
	int ans = max(v1.back(), v2.back());
	for (auto &x : v1)
	{
		ans = max(ans, *(--lower_bound(v2.begin(), v2.end(), mod - x)) + x);
	}
	cout << ans << endl;
	return 0;
}