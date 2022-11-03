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
const int N = 2e2 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string str;
	cin >> n >> str;
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '.') continue;
		for (int j = 1; i + 4 * j < n; j++)
		{
			int f = 1;
			for (int k = 1; k <= 4; k++)
			{
				if (str[i + k *j] == '.') f = 0;
			}
			flag |= f;
		}
	}
	if (flag) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}