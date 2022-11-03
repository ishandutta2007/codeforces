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
const int N = 1e5 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	int a, b;
	cin >> n;
	cin >> a >> b;
	int ans = INF;
	int v[] = { a,a,a,a,b,b };
	sort(v, v + 6);
	do
	{
		int tot = 1;
		int cur = n;
		for (int i = 0; i < 6; i++)
		{
			if (cur >= v[i]) cur -= v[i];
			else tot++, cur = n - v[i];
		}
		ans = min(ans, tot);
	} while (next_permutation(v, v + 6));
	cout << ans << endl;
	return 0;
}