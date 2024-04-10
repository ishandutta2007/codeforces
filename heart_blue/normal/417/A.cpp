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
const long long INF = 1e9 + 7;

int main()
{
	//freopen("input.txt", "r", stdin);
	int c, d;
	int n, m, k;
	cin >> c >> d;
	cin >> n >> m >> k;
	int sum = n*m - k;
	if (sum <= 0)
	{
		cout << 0 << endl;
		return 0;
	}
	int ans = sum / n*c;
	if (sum%n) ans += c;
	for (int i = 0; i <= m; i++)
	{
		ans = min(ans, i*c + max(sum - i*n, 0)*d);
	}
	cout << ans << endl;
	return 0;
}