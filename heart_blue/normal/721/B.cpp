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
const int N = 2e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	int cnt1 = 0, cnt2 = 0;
	vector<string> vs(n);
	for (auto &str : vs) cin >> str;
	string pass;
	cin >> pass;
	for (auto & str : vs)
	{
		if (str.length() < pass.length()) cnt1++;
		else if (str.length() == pass.length()) cnt2++;
	}
	cout << (cnt1 + 1) + cnt1 / k * 5 << ' ' << (cnt1 + cnt2) + (cnt1 + cnt2 - 1) / k * 5 << endl;
	return 0;
}