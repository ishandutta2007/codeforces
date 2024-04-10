#pragma comment(linker, "/STACK:102400000,102400000") 
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
void ask(LL l, LL r)
{
	cout << l << ' ' << r << endl;
}
int getans()
{
	string str;
	cin >> str;
	if (str == "Bad") exit(0);
	return str == "Yes";
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector<int> v;
	for (int i = 0; i < 3000; i++) v.push_back(i);
	LL n, k;
	cin >> n >> k;
	LL l = 1, r = n;
	while (l <= r)
	{
		l = max(1LL, l);
		r = min(n, r);
		if (r - l + 1 <= 50)
		{
			random_shuffle(v.begin(), v.end());
			LL key = l + v[0] % (r - l + 1);
			ask(key, key);
			if (getans()) 
				exit(0);
			l -= k;
			r += k;
			continue;
		}
		LL mid = (l + r) >> 1;
		ask(l, mid);
		int ret = getans();
		if (ret) l -= k, r = mid + k;
		else l = mid - k, r += k;
	}
	return 0;
}