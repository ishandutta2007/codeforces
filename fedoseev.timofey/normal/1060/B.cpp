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
    ll n;
    cin >> n;
    string s = to_string(n);
    int ans = 0;
    for (auto c : s) {
    	ans += c - '0';
    }
    reverse(s.begin(), s.end());
    int x = 0;
    while (x < s.size() && s[x] == '9') ++x;
    int delta = 9 * ((int)s.size() - x - 1);
    delta = max(delta, 0);
    cout << ans + delta << '\n';
}