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
const int N = 2e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string key;
	cout << "5 0" << endl;
	cin >> key;
	int l = 1, r = 1e9;
	n--;
	int L = 0;
	int R = r;
	while (n--)
	{
		int mid = (l + r) / 2;
		cout << 5 << ' ' << mid << endl;
		string str;
		cin >> str;
		if (str == key) l = mid + 1, L = max(L, mid);
		else r = mid - 1, R = min(R, mid);
	}
	cout << 4 << ' ' << L << ' ' << 6 << ' ' << R << endl;
	return 0;
}