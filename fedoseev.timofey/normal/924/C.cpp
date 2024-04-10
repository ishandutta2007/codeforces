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
    ll ans = 0;
    multiset <int> x;
    for (int i = 0; i < n; ++i) {
        x.insert(a[i] + 1);
    }
    int cur = *x.rbegin();
    for (int i = n - 1; i >= 0; --i) {
        x.erase(x.find(a[i] + 1));
        int q;
        if (!x.empty()) q = *x.rbegin();
        else q = 0;
        if (q < cur) {
            ans += max(0, cur - a[i] - 1);
            --cur;
        }
        else {
            ans += max(0, cur - a[i] - 1);
        }
    }
    cout << ans << endl;
}