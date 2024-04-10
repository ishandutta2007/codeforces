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

const int N = 1e5 + 7;

vector <int> g[N];
int deg[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (deg[i] > 2) ++cnt;
    }
    if (cnt > 1) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    int ind = -1;
    for (int i = 0; i < n; ++i) {
        if (deg[i] > 2) ind = i;
    }
    if (ind == -1) {
        cout << "1\n";
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1) {
                cout << i + 1 << ' ';
            }
        }
    }
    else {
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1) ++cnt;
        }
        cout << cnt << '\n';
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1) {
                cout << ind + 1 << ' ' << i + 1 << '\n';
            }
        }
    }
}