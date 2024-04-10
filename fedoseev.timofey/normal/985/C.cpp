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
    int n, k, l;
    cin >> n >> k >> l;
    int m = n * k;
    vector <int> a(m);
    for (int i = 0; i < m; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int f = 0;
    int s = upper_bound(a.begin(), a.end(), a[0] + l) - a.begin();
    if (s - f < n) {
        cout << "0\n";
        return 0;
    }
    ll ans = 0;
    int last = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[last];
        last += k;
        if (last >= s - (n - i - 1)) {
            for (int j = s - (n - i - 1); j < s; ++j) {
                ans += a[j];
            }
            break;
        }
    }
    cout << ans << '\n';
}