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
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector <int> a(n + 2);
    for (int i = 0; i < n; ++i) cin >> a[i + 1];
    a[0] = 0;
    a[n + 1] = m;
    ll ans = 0;
    for (int i = 1; i < n + 2; i += 2) {
        ans += a[i] - a[i - 1];
    }
    vector <ll> pref(n + 2);
    vector <ll> suff(n + 2);
    pref[1] = a[1];
    for (int i = 2; i < n + 2; ++i) {
        pref[i] = pref[i - 2] + a[i] - a[i - 1];
    }
    suff[n] = a[n + 1] - a[n];
    for (int i = n - 1; i >= 0; --i) {
        suff[i] = suff[i + 2] + a[i + 1] - a[i];
    }
    for (int i = 1; i + 1 < n + 2; ++i) {
        if (a[i] == a[i - 1] + 1 && a[i] + 1 == a[i + 1]) continue;
        if (i % 2 == 1) {
            ans = max(ans, pref[i] + suff[i] - 1);
        }
        else {
            ans = max(ans, pref[i - 1] + suff[i + 1] + 1);
        }  
    }
    cout << ans << '\n';
}