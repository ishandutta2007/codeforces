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
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % k) {
        cout << "No\n";
        return 0;
    }
    sum /= k;
    vector <int> ans;
    int lst = -1;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += a[i];
        if (cur > sum) {
            cout << "No\n";
            return 0;
        }
        if (cur == sum) {
            ans.push_back(i - lst);
            lst = i;
            cur = 0;
        }
    }
    if (cur != 0) {
        cout << "No\n";
    }
    else {
        cout << "Yes\n";
        for (auto x : ans) {
            cout << x << ' ';
        }
    }
}