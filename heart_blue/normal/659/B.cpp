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
const int N = 1e4 + 10;
vector<pair<int, string>> vp[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	while (n--)
	{
		string name;
		int r, score;
		cin >> name >> r >> score;
		vp[r].push_back({ score,name });
	}
	for (int i = 1; i <= m; i++)
	{
		if (vp[i].size() <= 1)
		{
			cout << "?" << endl;
			continue;
		}
		sort(vp[i].rbegin(), vp[i].rend());
		if (vp[i].size() >= 3 && vp[i][1].first == vp[i][2].first)
		{
			cout << "?" << endl;
			continue;
		}
		cout << vp[i][0].second << ' ' << vp[i][1].second << endl;
	}
	return 0;
}