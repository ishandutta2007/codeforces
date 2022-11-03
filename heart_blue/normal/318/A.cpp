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
	
	LL n, k;
	cin >> n >> k;
	if (n % 2 == 0)
	{
		if (k * 2 <= n) cout << k * 2 - 1 << endl;
		else cout << (k-n/2) * 2 << endl;
	}
	else
	{
		if (k * 2 <= n + 1) cout << k * 2 - 1 << endl;
		else cout << (k - (n + 1) / 2) * 2 << endl;
	}
	return 0;
}