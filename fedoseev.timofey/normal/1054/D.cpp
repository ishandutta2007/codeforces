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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map <int, int> cnt;
    ++cnt[0];
    ll ans = 0;
    int pref = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        int y = a[i];
        for (int i = 0; i < k; ++i) {
            y ^= (1 << i);
        }
        int b = pref ^ x;
        int c = pref ^ y;
        if (cnt[b] < cnt[c]) {
            ans += cnt[b];
            ++cnt[b];
            pref = b;
        }
        else {
            ans += cnt[c];
            ++cnt[c];
            pref = c;
        }
    }
    cout << (ll)n * (n + 1) / 2 - ans << '\n';
}