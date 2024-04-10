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
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <int> was(1001);
    vector <int> ans;
    for (int i = n - 1; i >= 0; --i) {
        if (!was[a[i]]) {
            ans.push_back(a[i]);
            was[a[i]] = 1;
        }
    }
    cout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    for (auto e : ans) {
        cout << e << ' ';
    }
}