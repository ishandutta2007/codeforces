#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 250 * 1000 + 100;

int d[size], h[size];
int n, m;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
    	scanf("%d%d", &d[i], &h[i]);
    }

    bool flag = true;
    int ans = 0;
	for (int i = 0; i < m; i++)
		ans = max(ans, h[i]);

	ans = max(ans, (h[0] + d[0] - 1));
	for (int i = 0; i < m - 1; i++) {
		if (d[i + 1] - d[i] < abs(h[i] - h[i + 1])) {
			flag = false;
		}

		ans = max(ans, max(h[i], h[i + 1]) + (d[i + 1] - d[i] - abs(h[i] - h[i + 1])) / 2);
	}
	ans = max(ans, (h[m - 1] + (n - d[m - 1])));

	if (!flag)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << ans << endl;

    return 0;
}