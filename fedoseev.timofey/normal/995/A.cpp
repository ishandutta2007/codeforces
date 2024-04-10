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
#include <cassert>

using namespace std;

typedef long long ll;

int a[4][53];

int n;
struct triple {
    int a, b, c;
    triple(int a, int b, int c) : a(a), b(b), c(c) {}
};

vector <triple> ans;

bool find() {
    bool bad = true;
    for (int i = 0; i < n; ++i) {
        if (a[1][i] == a[0][i] && a[1][i]) {
            bad = false;
            ans.emplace_back(a[0][i], 1, i + 1);
            a[0][i] = a[1][i] = 0;
            break;
        }
        if (a[2][i] == a[3][i] && a[2][i]) {
            ans.emplace_back(a[2][i], 4, i + 1);
            bad = false;
            a[2][i] = a[3][i] = 0;
            break;
        }
    }
    if (!bad) return 1;
    else return 0;
}

void next(int x, int y, int &nx, int &ny) {
    if (x == 1) {
        if (y == n - 1) {
            nx = 2;
            ny = n - 1;
        }
        else {
            nx = 1;
            ny = y + 1;
        }
    }
    else {
        if (y == 0) {
            nx = 1;
            ny = 0;
        }
        else {
            nx = 2;
            ny = y - 1;
        }
    }
}

bool ok() {
    bool bad = false;
    for (int i = 1; i <= 2; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != 0) {
                bad = true;
                break;
            }
        }
        if (bad) break;
    }
    return !bad;
}

void shift() {
    int x = -1, y = -1;
    for (int i = 1; i <= 2; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 0) {
                x = i;
                y = j;
            }
        }
    }
    assert(x != -1 && y != -1);
    int nx, ny;
    int tx = x, ty = y;
    next(x, y, nx, ny);
    while (nx != tx || ny != ty) {
        a[x][y] = a[nx][ny];
        if (a[nx][ny]) ans.emplace_back(a[nx][ny], x + 1, y + 1);
        x = nx;
        y = ny;
        next(nx, ny, nx, ny);
    }
    a[x][y] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int k;
    cin >> n >> k;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
        	cin >> a[i][j];
        }
    }
    if (k == 2 * n) {
        if (!find()) {
            cout << "-1\n";
            return 0;
        }
    }
    while (!ok()) {
        if (!find()) {
            shift();
        }
        /*for (int i = 0; i < 4; ++i) {
        	for (int j = 0; j < n; ++j) {
        		cout << a[i][j] << ' ';
        	}
        	cout << '\n';
        }
        cout << '\n'; */
    }
    cout << ans.size() << '\n';
    for (auto &e : ans) {
        cout << e.a << ' ' << e.b << ' ' << e.c << '\n';
    }
}