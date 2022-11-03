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
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
vector<int> v[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	str.push_back('#');
	int cnt = 1;
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i - 1] != str[i]) v[str[i - 1] - 'a'].push_back(cnt), cnt = 1;
		else cnt++;
	}
	int ans = 0;
	for (int i = 0; i < 26; i++)
	{
		int sum = 0;
		for (auto &x : v[i]) sum += x / k;
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}