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

bool query(int r1, int c1, int r2, int c2) {
    cout << "? " << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << endl;
    string s;
    cin >> s;
    if (s == "YES") return 1;
    else if (s == "NO") return 0;
    else if (s == "BAD") exit(0);
    else assert(0);
}

int n;

bool ok(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main() {
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cin.tie(0);
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    vector <char> L, R;
    int cr = 1, cc = 1;
    while ((n - cc) + (n - cr) > n - 1) {
        if (ok(cr, cc + 1) && query(cr, cc + 1, n, n)) {
            L.push_back('R');
            ++cc;
        }
        else {
            L.push_back('D');
            ++cr;
        }
    }
    cr = n, cc = n;
    while ((cr - 1) + (cc - 1) > n - 1) {
        if (ok(cr - 1, cc) && query(1, 1, cr - 1, cc)) {
            --cr;
            R.push_back('D');
        }
        else {
            --cc;
            R.push_back('R');
        }
    }
    cout << "! ";
    for (auto e : L) {
        cout << e;
    }
    reverse(R.begin(), R.end());
    for (auto e : R) {
        cout << e;
    }
    cout << endl;
}