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

const int Inf = 1e9;

int n;

bool ok(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int k;
    cin >> n >> k;
    vector <vector <char>> f(n + 1, vector <char> (n + 1));
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            f[i][j + 1] = s[j];
        }
    }
    vector <vector <int>> dp(n + 1, vector <int> (n + 1, Inf));
    dp[0][1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + (f[i][j] != 'a');
        }
    }
    int x = 0, y = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dp[i][j] <= k && i + j > x + y) {
                x = i;
                y = j;
            }
        }
    }
    set <pair <int, int>> cur;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dp[i][j] <= k && i + j == x + y) {
                cur.insert({i, j});
            }
        }
    }
    cur.insert({x, y});
    string ans(x + y - 1, 'a');
    string now = "";
    int sum = x + y - 1;
    while (sum < 2 * n - 1) {
        ++sum;
        set <pair <int, int>> ni;
        for (auto p : cur) {
            int i = p.first;
            int j = p.second;
            if (ok(i + 1, j)) ni.insert({i + 1, j});
            if (ok(i, j + 1)) ni.insert({i, j + 1});
        }
        char bst = 'z';
        for (auto p : ni) {
            int i = p.first;
            int j = p.second;
            if (f[i][j] < bst) bst = f[i][j];
        }
        now += bst;
        cur.clear();
        for (auto p : ni) {
            int i = p.first;
            int j = p.second;
            if (f[i][j] == bst) {
                cur.insert({i, j});
            }
        }
    }
    cout << ans << now << '\n';
}