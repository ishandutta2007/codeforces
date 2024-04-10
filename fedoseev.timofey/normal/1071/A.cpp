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
    int a, b;
    cin >> a >> b;
    int l = 0, r = 1e5;
    while (r - l > 1) {
        int ta = a, tb = b;
        int m = (l + r) >> 1;
        vector <int> used(m + 1);
        for (int i = m; i >= 1; --i) {
            if (ta >= i) {
                used[i] = 1;
                ta -= i;
            }
        }
        for (int i = m; i >= 1; --i) {
            if (!used[i]) {
                if (tb >= i) {
                    used[i] = 1;
                    tb -= i;
                }
                else {
                    break;
                }
            }
        }
        bool fl = 1;
        for (int i = 1; i <= m; ++i) {
            if (!used[i]) {
                fl = 0;
                break;
            }
        }
        if (fl) l = m;
        else r = m;
    }
    vector <int> used(l + 1);
    vector <int> aa, bb;
    for (int i = l; i >= 1; --i) {
        if (a >= i) {
            used[i] = 1;
            a -= i;
            aa.push_back(i);
        }
    }
    for (int i = l; i >= 1; --i) {
        if (!used[i]) {
            b -= i;
            bb.push_back(i);
        }
    }
    cout << aa.size() << "\n";
    for (auto x : aa) {
        cout << x << ' ';
    }
    cout << '\n';
    cout << bb.size() << '\n';
    for (auto x : bb) {
        cout << x << ' ';
    }
}