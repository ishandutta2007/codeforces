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
const int N = 1e5 + 10;
pair<int,int> a[N];
pair<int,int> b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, v;
	cin >> n >> v;
	int k1, k2;
	k1 = k2 = 1;
	for (int i = 0; i < n; i++)
	{
		int o, x;
		cin >> o >> x;
		if (o == 1) a[k1++] = { x,i + 1 };
		else b[k2++] = { x,i + 1 };
	}
	sort(a + 1, a + k1);
	reverse(a + 1, a + k1);
	sort(b + 1, b + k2);
	reverse(b + 1, b + k2);
	a[0].first = b[0].first = 0;
	k1--, k2--;
	for (int i = 1; i <= k1; i++) a[i].first += a[i - 1].first;
	for (int j = 1; j <= k2; j++) b[j].first += b[j - 1].first;
	int key = 0;
	for (int j = 0; j <= min(k2, v / 2); j++)
	{
		if (b[key].first + a[min(v - key * 2, k1)].first < b[j].first + a[min(v - j * 2, k1)].first)
			key = j;
	}
	cout << b[key].first + a[min(v - key * 2, k1)].first << endl;
	vector<int> ans;
	for (int i = 1; i <= key; i++) ans.push_back(b[i].second);
	for (int i = 1; i <= min(v - key * 2, k1); i++) ans.push_back(a[i].second);
	sort(ans.begin(), ans.end());
	for (auto &x : ans) cout << x << ' ';
	return 0;
}