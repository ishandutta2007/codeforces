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

vector <int> a;

set <int> can;

int get(int x) {
    int res = 2e9 + 7;
    for (int i = 0; i < a.size(); ++i) {
        res = min(res, abs(x - a[i]));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(0); cin.tie(0);
    srand(time(0));
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, d;
    cin >> n >> d;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (get(a[i] - d) == d) {
            can.insert(a[i] - d);
        }
        if (get(a[i] + d) == d) {
            can.insert(a[i] + d);
        }
    }
    cout << can.size() << '\n';
}