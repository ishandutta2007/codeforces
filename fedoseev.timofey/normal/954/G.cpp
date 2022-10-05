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

const int N = 5e5 + 7;
int n, r;
ll k;

int a[N];

ll prefix[N];
ll cur[N];

ll get(int l, int r) {
    l = max(l, 0);
    r = min(r, n - 1);
    return prefix[r + 1] - prefix[l];
}

bool check(ll x) {
    vector <ll> delta(n);
    ll s = 0;
    ll have = k;
    for (int i = 0; i < n; ++i) {
        if (i > r) {
            s -= delta[i - r - 1];
        }
        if (cur[i] + s >= x) continue;
        ll need = x - (cur[i] + s);
        if (need > have) {
            return false;
        }
        have -= need;
        delta[min(n - 1, i + r)] += need;
        s += need;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> r >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }
    ll mn = 2e18;
    for (int i = 0; i < n; ++i) {
        cur[i] = get(i - r, i) + get(i, i + r) - a[i];
        mn = min(mn, cur[i]);
    }
    ll left = mn;
    ll right = 2e18;
    while (right - left > 1) {
        ll mid = (left + right) >> 1;
        if (check(mid)) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    cout << left << "\n";
}