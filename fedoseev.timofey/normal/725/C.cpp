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

const int L = 13;

int n;

void get_pos(int &i, int &j) {
    if (i == 0) {
        --j;
        if (j < 0) {
            i = 1;
            j = 0;
        }
    }
    else {
        ++j;
    }
}

void get_next(int &i) {
    ++i;
    if (i == n) i = 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin >> s;
    int id1 = -1, id2 = -1;
    n = s.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j]) {
                id1 = i;
                id2 = j;
            }
        }
    }
    if (id1 + 1 == id2) {
        cout << "Impossible\n";
        return 0;
    }
    vector <vector <char>> ans(2, vector <char> (L));
    int h, l;
    if ((id2 - id1) & 1) {
        int ct = id2 - id1 - 1;
        h = l = ct / 2;
    }
    else {
        int ct = id2 - id1 - 1;
        h = ct / 2;
        l = (ct + 1) / 2;
    }
    for (int i = 0, idx = id1 + 1, pos = L - h; i < h; ++i, ++idx, ++pos) {
        ans[0][pos] = s[idx];
    }
    for (int i = 0, idx = id1 + 1 + h, pos = L - 1; i < l; ++i, ++idx, --pos) {
        ans[1][pos] = s[idx];
    }
    ans[0][L - h - 1] = s[id1];
    int i = 0;
    int j = L - h - 1;
    int uk = id2;
    while (true) {
        get_next(uk);
        get_pos(i, j);
        if (uk == id1) break;
        ans[i][j] = s[uk];
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < L; ++j) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}