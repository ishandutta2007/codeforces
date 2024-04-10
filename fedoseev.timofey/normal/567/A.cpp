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

const int Inf = 2e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <pair <int, int>> a(n);
    vector <pair <int, int>> ans(n, make_pair(Inf, -Inf));
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        if (i) {
            ans[a[i].second].first = min(ans[a[i].second].first, a[i].first - a[i - 1].first);
            ans[a[i].second].second = max(ans[a[i].second].second, a[i].first - a[0].first);
        }
        if (i != n - 1) {
            ans[a[i].second].first = min(ans[a[i].second].first, a[i + 1].first - a[i].first);
            ans[a[i].second].second = max(ans[a[i].second].second, a[n - 1].first - a[i].first);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}