#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

int ax, ay, bx, by, cx, cy;

vector <int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
vector <int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

const int N = 1007;

int bad[N][N];
int used[N][N];

int n;

bool ok(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < n);
}

void dfs(int x, int y) {
	used[x][y] = 1;
	for (int i = 0; i < 8; ++i) {
		if (ok(x + dx[i], y + dy[i]) && !used[x + dx[i]][y + dy[i]] && !bad[x + dx[i]][y + dy[i]]) dfs(x + dx[i], y + dy[i]);
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    --ax, --ay, --bx, --by, --cx, --cy;
    for (int i = 0; i < 8; ++i) {
    	int x = ax;
    	int y = ay;
    	while (ok(x, y)) {
    		bad[x][y] = 1;
    		x += dx[i];
    		y += dy[i];
    	}
    }
    dfs(bx, by);
    if (used[cx][cy]) cout << "YES\n";
    else cout << "NO\n";
}