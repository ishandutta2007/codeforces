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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
vector<string> vs1, vs2;
int a[N];
int n;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	cin >> n >> t;
	vs1.resize(n);
	vs2.resize(n);
	for (int i = 0; i < n; i++) cin >> vs1[i] >> vs2[i] >> a[i];
	map<pair<string, string>, int> ans;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n && a[i] + t >= a[j]; j++)
		{
			if (a[i] == a[j]) continue;
			if (vs1[i] == vs2[j] && vs1[j] == vs2[i])
			{
				string s1 = vs1[i];
				string s2 = vs2[i];
				if (s1 > s2) swap(s1, s2);
				ans[{s1, s2}] = 1;
				break;
			}
		}
	}
	cout << ans.size() << endl;
	for (auto &p : ans)
	{
		cout << p.first.first << ' ' << p.first.second << endl;
	}
	return 0;
}