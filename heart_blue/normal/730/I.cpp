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
const int N = 3e3 + 10;
int dp[N][N];
pair<int, int> pre[N][N];
int d[N][N];
class Student
{
public:
	int a;
	int b;
	int num;
	bool operator < (const Student &s) const
	{
		return a > s.a;
	}
};
vector<Student> vs;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, s, p;
	cin >> n >> s >> p;
	vs.resize(n + 1);
	for (int i = 0; i <= n; i++) vs[i].num = i;
	for (int i = 1; i <= n; i++) cin >> vs[i].a;
	for (int i = 1; i <= n; i++) cin >> vs[i].b;
	sort(vs.begin() + 1, vs.end());
	MEM(dp, 0);
	int ans = 0;
	int x, y;
	pre[0][0] = { -1,-1 };
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= min(i, p); j++)
		{
			//int t1 = (i - 1 >= j ? dp[i - 1][j] : 0) + (i - j > s ? 0 : vs[i].a);
			int t1 = 0;
			if (i - 1 >= j)
			{
				t1 = dp[i - 1][j];
				if (i - j <= s) t1 += vs[i].a;
			}
			//int t2 = (j > 0 ? dp[i - 1][j - 1] : 0) + (j > p ? 0 : vs[i].b);
			int t2 = 0;
			if (j > 0)
			{
				t2 = dp[i - 1][j - 1];
				if (j <= p) t2 += vs[i].b;
			}
			dp[i][j] = max(t1, t2);
			if (t1 >= t2)
			{
				d[i][j] = 0;
				pre[i][j] = { i - 1,j };
			}
			else
			{
				d[i][j] = 1;
				pre[i][j] = { i - 1,j - 1 };
			}
			//cout << i << ' ' << j << ' ' << d[i][j] << ' ' << dp[i][j] << endl;
			if (ans < dp[i][j])
			{
				x = i, y = j;
				ans = dp[i][j];
			}
		}
	}
	vector<int> res[2];
	while (x != 0)
	{
		int px, py;
		tie(px, py) = pre[x][y];
		//cout << x << ' ' << y << endl;
		if (dp[x][y] != dp[px][py])
		{
			res[d[x][y]].push_back(vs[x].num);
		}
		x = px;
		y = py;
	}
	cout << ans << endl;
	sort(res[0].begin(), res[0].end());
	sort(res[1].begin(), res[1].end());
	for (auto &x : res[0]) cout << x << ' ';
	cout << endl;
	for (auto &x : res[1]) cout << x << ' ';
	cout << endl;

	return 0;
}