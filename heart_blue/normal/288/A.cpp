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
const int N = 5e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	if (n < k)
	{
		cout << -1 << endl;
	}
	else
	{
		if (k == 1)
		{
			if (n == 1) cout << "a" << endl;
			else cout << -1 << endl;
		}
		else
		{
			string str;
			for (int i = 0; i < n; i++) str.push_back((i & 1) + 'a');
			int l = n - 1;
			for (int i = k - 1; i >= 2; i--)
			{
				str[l--] = i + 'a';
			}
			cout << str << endl;
		}
	}
	return 0;
}