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

vector <int> a;
vector <int> cnt;
vector <int> who;

int c, n;

bool check(int y) {
    ++cnt[y];
    bool fl = false;
    if (cnt[y] == 1) {
        fl = true;
    }
    int cur = c;
    int mnuse = c + 1;
    bool bad = false;
    while (cur > 0) {
        int w = min(cur, mnuse - 1);
        int x = who[w];
        int ct = (x == -1 ? 0 : cnt[x]);
        if (fl && y > x && y <= cur) {
            x = y;
            ct = 1;
            fl = false;
        }
        if (x == -1) {
            bad = true;
            break;
        }
        else {
            mnuse = x;
            ct = min(ct, (cur - (x - 1) + x - 1) / x);
            cur -= x * ct;
        }
    }
    --cnt[y];
    return !bad;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> c >> n;
    a.resize(n);
    cnt.resize(c + 1);
    who.resize(c + 1, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= c; ++i) {
        int id = upper_bound(a.begin(), a.end(), i) - a.begin();
        if (id > 0) who[i] = a[id - 1];
    }
    for (int i = 1; i < c; ++i) {
        if (!check(i)) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << "Greed is good\n";
}