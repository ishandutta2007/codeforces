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

const int n = 14;

vector <int> a(n);

ll solve(int i) {
    vector <int> tmp = a;
    int have = a[i];
    a[i] = 0;
    for (int j = 1; j <= 14; ++j) {
        a[(i + j) % n] += have / n + (have % n >= j);
    }
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) res += a[i];
    }
    a = tmp;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, solve(i));
    }
    cout << ans << '\n';
}