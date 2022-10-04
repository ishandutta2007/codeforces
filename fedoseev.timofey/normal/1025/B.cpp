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

vector <int> get(int x) {
    vector <int> res;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            res.push_back(i);
            while ((x % i) == 0) x /= i;
        }
    }
    if (x != 1) res.push_back(x);
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cin.tie(0);
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <pair <int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    vector <int> b = get(a[0].first);
    vector <int> c = get(a[0].second);
    for (auto x : b) {
        bool bad = false;
        for (auto &p : a) {
            if ((p.first % x) != 0 && (p.second % x) != 0) {
                bad = true;
                break;
            }
        }
        if (!bad) {
            cout << x << '\n';
            return 0;
        }
    }
    for (auto x : c) {
        bool bad = false;
        for (auto &p : a) {
            if ((p.first % x) != 0 && (p.second % x) != 0) {
                bad = true;
                break;
            }
        }
        if (!bad) {
            cout << x << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}