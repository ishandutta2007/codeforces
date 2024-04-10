#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <ctime>

#define ll long long
#define dl double long
#define graph vector <vector <int>> 
#define read_edge(g) int u, v; cin >> u >> v; u--; v--; g[u].push_back(v); g[v].push_back(u)
#define read_graph(g) forin(i, m) { read_edge(g); }
#define all_graph(g, n) graph g(n); read_graph(g)
#define all(a) a.begin(), a.end()
#define forin(i, n) for (int i = 0; i < n; i++)
#define fsp(n) fixed << setprecision(n)

using namespace std;

const ll llINF = 8e18, MAX_LL = (1ll << 63) - 1, llMOD = 1e9 + 7;
const int INF = 1e9, MAX_INT = (1ll << 31) - 1, MOD = 1e9 + 7;
const dl EPS = 1e-10, PI = acos(-1);

int main() {
	int n, s;
	cin >> n >> s;
	if (s == 0) {
		if (n == 1)
			cout << "0 0";
		else
			cout << "-1 -1";
		return 0;
	}
	vector <int> ans1(n), ans2(n);
	int copy_s = s - 1, itans1 = n - 1;
	ans1[0] = 1;
	while (copy_s > 0 && itans1 >= 0) {
		if (copy_s <= 9) {
			ans1[itans1] += copy_s;
			copy_s = 0;
			break;
		}
		ans1[itans1] += 9;
		copy_s -= 9;
		itans1--;
	}
	if (copy_s == 0 && ans1[0] < 10)
		for (auto now : ans1)
			cout << now;
	else
		cout << "-1";
	cout << " ";
	copy_s = s, itans1 = 0;
	while (copy_s > 0 && itans1 <= n - 1) {
		if (copy_s <= 9) {
			ans2[itans1] += copy_s;
			copy_s = 0;
			break;
		}
		ans2[itans1] = 9;
		copy_s -= 9;
		itans1++;
	}
	if (copy_s == 0)
		for (auto now : ans2)
			cout << now;
	else
		cout << "-1";
	return 0;
}