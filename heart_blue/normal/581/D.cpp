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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<pair<int, int>> vp(3);
bool check(string &str)
{
	int h1, w1, h2, w2, h3, w3;
	tie(h1, w1) = vp[str[0] - 'A'];
	tie(h2, w2) = vp[str[1] - 'A'];
	tie(h3, w3) = vp[str[2] - 'A'];
	if (w1 == w2 && w2 == w3)
	{
		if (w1 != h1 + h2 + h3) return false;
		cout << w1 << endl;
		for (int i = 0; i < h1; i++) cout << string(w1, str[0]) << endl;
		for (int i = 0; i < h2; i++) cout << string(w2, str[1]) << endl;
		for (int i = 0; i < h3; i++) cout << string(w3, str[2]) << endl;
		return true;
	}
	if (h2 == h3 && w2 + w3 == w1)
	{
		if (w1 != h1 + h2) return false;
		cout << w1 << endl;
		for (int i = 0; i < h1; i++) cout << string(w1, str[0]) << endl;
		for (int i = 0; i < h2; i++) cout << string(w2, str[1]) << string(w3, str[2]) << endl;
		return true;
	}
	return false;

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (auto &p : vp) cin >> p.first >> p.second;
	for (int o = 0; o < 8; o++)
	{
		for (int i = 0; i < 3; i++) if (o >> i & 1) swap(vp[i].first, vp[i].second);
		string str = "ABC";
		do
		{
			if (check(str)) return 0;
		} while (next_permutation(str.begin(), str.end()));
		for (int i = 0; i < 3; i++) if (o >> i & 1) swap(vp[i].first, vp[i].second);
	}
	cout << -1 << endl;
	return 0;
}