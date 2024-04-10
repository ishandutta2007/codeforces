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

ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cin.tie(0);
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t, w, b;
    cin >> t >> w >> b;
    ll g = gcd(w, b);
    if ((ld)(w / g) * b > t) {
        ll have = min(t, min(w, b) - 1);
        ll tmp = gcd(have, t);
        have /= tmp;
        t /= tmp;
        cout << have << '/' << t << '\n';
    }
    else {
        ll l = (w / g) * b;
        ll step = min(w, b);
        ll have = t / l;
        ll all = 0;
        all += (have - 1) * step;
        all += min(t - l * have + 1, step);
        all += min(t, step - 1);
        ll tmp = gcd(all, t);
        all /= tmp;
        t /= tmp;
        cout << all << '/' << t << '\n';
    }
}