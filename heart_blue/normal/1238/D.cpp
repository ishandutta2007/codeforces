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
const int N = 3e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int len;
	cin >> len;
	string str;
	cin >> str;
	str.push_back('#');
	vector<int> v;
	int cnt = 1;
	for (int i = 1; i <= len; i++)
	{
		if (str[i] != str[i - 1])
		{
			v.push_back(cnt);
			cnt = 0;
		}
		cnt++;
	}
	LL ans = 1LL * len * (len - 1) / 2;
	for (int i = 0; i + 1 < v.size(); i++)
	{
		ans -= v[i] + v[i + 1] - 1;
	}
	cout << ans << endl;
	return 0;
}