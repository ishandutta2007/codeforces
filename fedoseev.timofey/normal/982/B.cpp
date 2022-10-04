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
    int n;
    cin >> n;
    vector <int> w(n);
    for (int i = 0; i < n; ++i) cin >> w[i];
    multiset <pair <int, int>> a, b;
    for (int i = 0; i < n; ++i) {
        a.insert(make_pair(w[i], i));
    }
    vector <int> ans(2 * n);
    string s;
    cin >> s;
    for (int i = 0; i < 2 * n; ++i) {
        if (s[i] == '0') {
            ans[i] = a.begin() -> second;
            b.insert(*a.begin());
            a.erase(a.begin());
        }
        else {
            ans[i] = b.rbegin() -> second;
            b.erase(--b.end());
        }
    }
    for (int i = 0; i < 2 * n; ++i) {
        cout << ans[i] + 1 << ' ';
    }
}