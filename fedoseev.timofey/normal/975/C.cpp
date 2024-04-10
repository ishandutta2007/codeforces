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
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <ll> ps(n);
    ps[0] = a[0];
    for (int i = 1; i < n; ++i) {
        ps[i] = ps[i - 1] + a[i];
    }
    ll sum = 0;
    for (int i = 0; i < q; ++i) {
        ll k;
        cin >> k;
        sum += k;
        int cnt = upper_bound(ps.begin(), ps.end(), sum) - ps.begin();
        if (cnt == n) {
            cout << n << '\n';
            sum = 0;
        }
        else {
            cout << n - cnt << '\n';
        }
    }
}