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

const int md = 1e9 + 7;

int mul(int a, int b) {
    return ((ll)a * b) % md;
}

int mpow(int a, ll n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        int t = mpow(a, n / 2);
        return mul(t, t);
    }
    else {
        return mul(a, mpow(a, n - 1));
    }
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) a += md;
    return a;
}

int inv(int a) {
    return mpow(a, md - 2);
}

int sum(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll x, k;
    cin >> x >> k;
    if (x == 0) {
        cout << "0\n";
        return 0;
    }
    x %= md;
    int r = mul(x, mpow(2, k));
    int cnt = sub(mpow(2, k), 1);
    int l = sub(r, cnt);
    r = mul(r, 2);
    l = mul(l, 2);
    cout << mul(sum(l, r), inv(2)) << '\n';
}