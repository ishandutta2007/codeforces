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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    vector <pair <int, int>> r(n);
    vector <vector <int>> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i].first;
        r[i].second = i;
        a[i] = r[i].first;
    }
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    sort(r.begin(), r.end());
    vector <int> ans(n);
    for (int i = 0; i < n; ++i) {
        if (!i) {
            ans[r[i].second] = 0;
        }
        else {
            int cnt = upper_bound(r.begin(), r.end(), make_pair(r[i].first, -1)) - r.begin();
            for (auto x : g[r[i].second]) {
                if (a[x] < r[i].first) {
                    --cnt;
                }
            }
            ans[r[i].second] = cnt;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}