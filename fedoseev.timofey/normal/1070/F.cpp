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


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    int ans = 0;
    int cA = 0;
    int cnt = 0;
    vector <int> a, b, c;
    for (int i = 0; i < n; ++i) {
        string s; int t;
        cin >> s >> t;
        if (s == "11") {
            ans += t;
            ++cA;
            ++cnt;
        }
        else if (s == "10") a.push_back(t);
        else if (s == "01") b.push_back(t);
        else c.push_back(t);
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int x = min(a.size(), b.size());
    for (int i = 0; i < x; ++i) {
        ans += a[i];
        ans += b[i];
    }
    cA += x;
    cnt += 2 * x;
    if (b.size() != x) swap(a, b);
    for (int i = x; i < a.size(); ++i) {
        c.push_back(a[i]);
    }
    sort(c.rbegin(), c.rend());
    int can = 2 * cA - cnt;
    for (int i = 0; i < min((int)c.size(), can); ++i) {
        ans += c[i];
    }
    cout << ans << '\n';
}