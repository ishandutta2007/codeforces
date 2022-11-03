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
const LL INF = 1e9 + 1;
const int N = 2e6;
int a[10];
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	cin >> str;
	int ans = 0;
	int cnt = 1;
	str.push_back('k');
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == str[i - 1]) cnt++;
		else
		{
			ans += cnt / 5;
			if (cnt % 5) ans++;
			cnt = 1;
		}
	}
	cout << ans << endl;

	return 0;
}