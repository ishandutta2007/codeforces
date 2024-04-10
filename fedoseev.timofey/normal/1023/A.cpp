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
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cin.tie(0);
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    if (s == t) {
        cout << "YES\n";
        return 0;
    }
    int id = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') id = i;
    }
    if (id == -1) {
        cout << "NO\n";
        return 0;
    }
    string a = s.substr(0, id);
    string b = s.substr(id + 1, n - (id + 1));
    if (a.size() + b.size() > t.size()) {
        cout << "NO\n";
        return 0;
    }
    if (a == t.substr(0, a.size()) && b == t.substr(m - b.size(), b.size())) {
        cout << "YES\n";
        return 0;
    }
    else {
        cout << "NO\n";
    }
}