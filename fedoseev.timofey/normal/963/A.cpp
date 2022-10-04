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

const int md = 1e9 + 9;

int add(int a, int b) {
    int c = a + b;
    if (c < 0) c += md;
    c %= md;
    return c;
}

int mul(int a, int b) {
    return ((ll)a * b) % md;
}

int mpow(int a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        int t = mpow(a, n / 2);
        return mul(t, t);
    }
    return mul(a, mpow(a, n - 1));
}

int inv(int a) {
    return mpow(a, md - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    int x = 0;
    for (int i = 0; i < k; ++i) {
        x = add(x, (s[i] == '+' ? 1 : -1) * mul(mpow(a, n - i), mpow(b, i)));
    }
    int q = mul(mpow(b, k), inv(mpow(a, k)));
    int ans = 0;
    ++n;
    n /= k;
    if (q == 1) {
        ans = mul(x, n);
    }
    else {
        int c = mul(x, add(1, -1 * mpow(q, n)));
        int d = add(1, -1 * q);
        ans = mul(c, inv(d));
    }
    cout << ans << "\n";
}