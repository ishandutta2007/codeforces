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
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> v[N];
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	cin >> (str + 1);
	for (int i = 'a'; i <= 'z'; i++) v[i].push_back(0);
	for (int i = 1; i <= n; i++)
	{
		v[str[i]].push_back(i);
	}
	int q;
	cin >> q;
	while (q--)
	{
		string str;
		cin >> str;
		int cnt[200];
		MEM(cnt, 0);
		int ans = 0;
		for (auto& c : str)
		{
			cnt[c]++;
			ans = max(ans, v[c][cnt[c]]);
		}
		printf("%d\n", ans);
	}
	return 0;
}