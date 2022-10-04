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

string get(string s) {
    for (auto &ch : s) {
        ch = '0' + ((ch - '0') % 2);
    }
    reverse(s.begin(), s.end());
    while (s.size() < 18) s += '0';
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cin.tie(0);
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    map <string, int> cnt;
    for (int i = 0; i < t; ++i) {
        char c; string s;
        cin >> c >> s;
        if (c == '+') {
            ++cnt[get(s)];
        }
        else if (c == '-') {
            --cnt[get(s)];
        }
        else {
            cout << cnt[get(s)] << '\n';
        }
    }
}