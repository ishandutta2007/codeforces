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
const int N = 2e5 + 10;
int v[8][3];
map<tuple<int, int, int>, int> mv;
inline LL dis(int i, int j)
{
	LL dx = v[i][0] - v[j][0];
	LL dy = v[i][1] - v[j][1];
	LL dz = v[i][2] - v[j][2];
	return dx * dx + dy * dy + dz * dz;
}
bool dfs(int cur = 0)
{
	if (cur == 8)
	{
		vector<LL> vs;
		for (int i = 1; i < 8; i++) vs.push_back(dis(0, i));
		sort(vs.begin(), vs.end());
		if (vs[0] == vs[2] && vs[3] == vs[5] && vs[0] * 3 == vs[6] && vs[0] * 2 == vs[3])
		{
			puts("YES");
			for (int i = 0; i < 8; i++)
			{
				for (auto &x : v[i]) printf("%d ", x);
				puts("");
			}
			return true;
		}
		return false;
	}
	do
	{
		int flag = 1;
		for (int i = 0; i < cur; i++)
		{
			if (dis(i, cur) == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0) continue;
		if (dfs(cur + 1)) return true;
	} while (next_permutation(v[cur], v[cur] + 3));
	//sort(v[cur].begin(), v[cur].end());
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n = 9;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++) scanf("%d", &v[i][j]);
		sort(v[i], v[i] + 3);
	}
	if (!dfs()) puts("NO");
	return 0;
}