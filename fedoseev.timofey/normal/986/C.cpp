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

using namespace std;

typedef long long ll;

vector <int> a;

const int N = (1 << 22) + 7;

int used[2][N];

int n;
int have[N];

void dfs(int type, int x) {
    used[type][x] = 1;
    if (type == 0) {
        if (!used[1][x]) {
            dfs(1, x);
        }
    }
    else {
        if (!used[0][(1 << n) - 1 - x]) {
            if (have[(1 << n) - 1 - x]) dfs(0, (1 << n) - 1 - x);
        }
        for (int k = 0; k < n; ++k) {
            if ((x | (1 << k)) != x) {
                if (!used[1][x | (1 << k)]) {
                    dfs(1, x | (1 << k));
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int m;
    cin >> n >> m;
    vector <int> a(m);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        have[x] = 1;
        a[i] = x;
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if (!used[0][a[i]]) {
            ++ans;
            dfs(0, a[i]);
        }
    }
    cout << ans << '\n';
}