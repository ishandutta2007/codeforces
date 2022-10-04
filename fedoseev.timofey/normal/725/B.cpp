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

map <char, int> dt;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    dt['f'] = 0;
    dt['e'] = 1;
    dt['d'] = 2;
    dt['a'] = 3;
    dt['b'] = 4;
    dt['c'] = 5;
    string s;
    cin >> s;
    ll n = stoll(s.substr(0, (int)s.size() - 1));
    --n;
    char c = s[(int)s.size() - 1];
    ll ans = 0;
    ans += (n / 4) * (12 + 4);
    n %= 4;
    if (n == 1 || n == 3) {
        ans += 7;
    }
    ans += dt[c];
    cout << ans + 1 << '\n';
}