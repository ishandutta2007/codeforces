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

const int md = 998244353;

int mul(int a, int b) {
    return (ll)a * b % md;
}

int fp(int a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        int t = fp(a, n / 2);
        return mul(t, t);
    }
    return mul(a, fp(a, n - 1));
}

void add(int &a, int b) {
    a += b;
    if (a >= md) a -= md;
}

int main() {
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(0); cin.tie(0);
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int c = n - i - 1;
        int p = (c == 0 ? 1 : mul((c + 2), fp(2, c - 1)));
        add(ans, mul(a[i], p));
    }
    cout << ans << '\n';
}