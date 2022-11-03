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
const LL INF = 1e9 + 9;
const int N = 1e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		vp.push_back({ x,i });
	}
	sort(vp.rbegin(), vp.rend());
	int ans = 0;
	vector<int> key;
	for (int i = 0; i < k; i++)
	{
		ans += vp[i].first;
		key.push_back(vp[i].second);
	}
	key.push_back(0);
	sort(key.begin(), key.end());
	cout << ans << endl;
	key.back() = n;
	for (int i = 1; i < key.size(); i++)
	{
		cout << key[i] - key[i - 1] << ' ';
	}
	return 0;
}