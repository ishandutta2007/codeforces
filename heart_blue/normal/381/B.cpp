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
const int N = 5e3 + 10;

int a[N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v1, v2;
	MEM(a, 0);
	int n;
	int x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a[x]++;
	}
	for (int i = 0; i < N; i++)
	{
		if (a[i])
		{
			v1.push_back(i);
			if (a[i] > 1) v2.push_back(i);
		}
	}
	if (!v2.empty() && v1.back() == v2.back()) v2.pop_back();
	reverse(v1.begin(), v1.end());
	cout << v1.size() + v2.size() << endl;
	for (auto &x : v2) cout << x << ' ';
	for (auto &x : v1) cout << x << ' ';
	return 0;
}