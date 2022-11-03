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
const int N = 3e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int cnt1 = 0, cnt2 = 0;
	while (n--)
	{
		int x;
		cin >> x;
		if (x == 1) cnt1++;
		else cnt2++;
	}
	if (cnt1 && cnt2)
	{
		cout << 2 << ' ' << 1 << ' ';
		cnt1--, cnt2--;
	}
	else if(cnt1)
	{
		cout << 1 << ' ';
		cnt1--;
	}
	while (cnt2--) cout << 2 << ' ';
	while (cnt1--) cout << 1 << ' ';
	return 0;
}