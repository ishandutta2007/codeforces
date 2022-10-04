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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <ll> ps(n + 1);
    for (int i = 0; i < n; ++i) {
        ps[i + 1] = ps[i] + a[i];
    }
    for (int i = 0; i < m; ++i) {
        ll x;
        cin >> x;
        int ind = lower_bound(ps.begin(), ps.end(), x) - ps.begin() - 1;
        x -= ps[ind];
        cout << ind + 1 << ' ' << x << '\n';
    }
}