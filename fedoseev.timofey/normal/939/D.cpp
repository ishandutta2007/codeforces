#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;
typedef long long ll;

int d[26][26];

void relax() {
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            for (int k = 0; k < 26; ++k) {
                d[i][j] |= d[i][k] & d[k][j];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    set <pair <int, int>> change;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) continue;
        change.insert({a[i], b[i]});
    }
    for (int i = 0; i < 26; ++i) d[i][i] = 1;
    vector <pair <int, int>> ans;
    while (!change.empty()) {
        auto p = *change.begin();
        change.erase(change.begin());
        int c1 = p.first - 'a';
        int c2 = p.second - 'a';
        if (!d[c1][c2]) {
            d[c1][c2] = 1;
            d[c2][c1] = 1;
            ans.push_back({c1, c2});
            relax();
        }
    }
    cout << ans.size() << endl;
    for (auto p : ans) {
        cout << char(p.first + 'a') << " " << char(p.second + 'a') << endl;
    }
}