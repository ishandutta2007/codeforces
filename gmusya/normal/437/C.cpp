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
#define weighted_graph vector <vector <pair <int, int>>>
#define all(a) a.begin(), a.end()
#define forin(i, n) for (int i = 0; i < n; i++)

using namespace std;

const ll llINF = 8e18, MAX_LL = (1ll << 63) - 1, llMOD = 1e9 + 7;
const int INF = 1e9, MAX_INT = (1ll << 31) - 1;
const dl EPS = 1e-10, PI = acos(-1);

int main() {
	int n, m, cnt = 0;
	cin >> n >> m;
	vector <int> w(n);
	forin(i, n)
		cin >> w[i];
	forin(i, m) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		cnt += min(w[u], w[v]);
	}
	cout << cnt;
	return 0;
}