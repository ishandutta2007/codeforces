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
#include <cassert>

using namespace std;

typedef long long ll;

struct fr {
    int a, b;
    bool operator<(const fr &other) const {
        return a * other.b < b * other.a;
    }
};

map <fr, int> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int m;
    cin >> m;
    vector <fr> f(m);
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        int a = 0, b = 0;
        int tmp = 0;
        for (auto c : s) {
            if (c == '(' || c == '/') continue;
            if ('0' <= c && c <= '9') {
                tmp *= 10;
                tmp += c - '0';
            }
            else if (c == '+') {
                a = tmp;
                tmp = 0;
            }
            else if (c == ')') {
                a += tmp;
                tmp = 0;
            }
            else {
                assert(0);
            }
        }
        b = tmp;
        ++cnt[{a, b}];
        f[i] = {a, b};
    }
    for (int i = 0; i < m; ++i) {
        cout << cnt[f[i]] << " ";
    }
}