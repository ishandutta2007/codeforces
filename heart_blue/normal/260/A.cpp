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

const int INF = 1e9 + 7;
const int N = 1e3 + 10;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a, b, n;
	int flag = 0;
	cin >> a >> b >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if ((a * 10 + j) % b == 0)
			{
				if (!flag) cout << a;
				a = 0;
				flag = 1;
				cout << j;
				break;
			}
		}
	}
	if (!flag) cout << -1 << endl;
	return 0;
}