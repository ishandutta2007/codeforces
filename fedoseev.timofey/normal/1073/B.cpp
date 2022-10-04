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
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    reverse(a.begin(), a.end());
    vector <int> have(n);
    for (int i = 0; i < n; ++i) {
        have[a[i]] = 1;
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        if (!have[x]) {
            cout << 0 << ' ';
            continue;
        }
        int ans = 0;
        while (a.back() != x) {
            ++ans;
            have[a.back()] = 0;
            a.pop_back();
        }
        have[x] = 0;
        ++ans;
        a.pop_back();
        cout << ans << ' ';
    }
}