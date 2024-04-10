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
typedef long double ld;

const int Inf = 1e9;

struct line {
    ll k, b;
    line(ll k, ll b) : k(k), b(b) {}
};

ld inter(const line &a, const line &b) {
    return (a.b - b.b) / (ld)(b.k - a.k);
}

ll f(const line &a, ll x) {
    return a.k * x + a.b;
}

struct convex {
    vector <line> s;
    convex() {}
    void push(const line &a) {
        while (s.size() > 1) {
            auto b = s.back();
            auto c = s[s.size() - 2];
            if (inter(a, c) < inter(b, c)) {
                s.pop_back();
            }
            else {
                break;
            }
        }
        s.push_back(a);
    }
    ll get(ll x) {
        int l = -1, r = s.size() - 1;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (f(s[m], x) >= f(s[m + 1], x)) {
                l = m;
            }
            else {
                r = m;
            }
        }
        return f(s[l + 1], x);
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector <ll> dp(n, Inf);
    convex H;
    dp[0] = 0;
    H.push({b[0], dp[0]});
    for (int i = 1; i < n; ++i) {
        dp[i] = H.get(a[i]);
        H.push({b[i], dp[i]});
    }
    cout << dp[n - 1] << '\n';
}