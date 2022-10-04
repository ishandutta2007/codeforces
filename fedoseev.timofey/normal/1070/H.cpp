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
typedef unsigned long long ull;

const int P = 239;

ull gethash(string s) {
    ull h = 0;
    for (int i = 0; i < s.size(); ++i) {
        h = h * P + s[i];
    }
    return h;
}

map <ull, int> cnt;
map <ull, string> who;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        set <ull> have;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                ull cur = gethash(s.substr(i, j - i + 1));
                have.insert(cur);
            }
        }
        for (auto h : have) {
            ++cnt[h];
            if (cnt[h] == 1) who[h] = s;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        ll h = gethash(s);
        cout << cnt[h] << ' ';
        if (cnt[h] == 0) {
            cout << "-\n";
        }
        else {
            cout << who[h] << "\n";
        }
    }
}