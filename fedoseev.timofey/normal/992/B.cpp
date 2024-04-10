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

vector <int> divisors(int a) {
    vector <int> res;
    for (int d = 1; d * d <= a; ++d) {
        if (a % d == 0) {
            res.push_back(d);
            if (d * d != a) res.push_back(a / d);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

ll lcm(int a, int b) {
    return ((ll)a * b) / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int l, r, x, y;
    cin >> l >> r >> x >> y;
    vector <int> cur = divisors(y);
    int ans = 0;
    for (int i = 0; i < cur.size(); ++i) {
        for (int j = 0; j < cur.size(); ++j) {
            if (l <= cur[i] && cur[i] <= r && l <= cur[j] && cur[j] <= r) {
                int g = gcd(cur[i], cur[j]);
                ll l = lcm(cur[i], cur[j]);
                if (g == x && l == y) {
                    ++ans;
                }
            }
        }
    }
    cout << ans << '\n';
}