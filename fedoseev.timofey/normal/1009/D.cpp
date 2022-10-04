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

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

const int N = 1e5 + 7;

vector <int> g[N];

int main() {
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(0); cin.tie(0);
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    if (m + 1 < n) {
        cout << "Impossible\n";
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (gcd(i, j) == 1) {
                g[i].push_back(j);
                --m;
                if (m == 0) break;
            }
        }
        if (m == 0) break;
    }
    if (m == 0) {
        cout << "Possible\n";
        for (int i = 1; i <= n; ++i) {
            for (auto v : g[i]) {
                cout << i << ' ' << v << '\n';
            }
        }
    }
    else {
        cout << "Impossible\n";
    }
}