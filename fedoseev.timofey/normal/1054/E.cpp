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

struct turn {
    int a, b, c, d;
    turn(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
};

int n, m;

vector <turn> get(vector <vector <string>> cur) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            reverse(cur[i][j].begin(), cur[i][j].end());
        }
    }
    vector <turn> ans;
    for (int i = 0; i < cur[0][0].size(); ++i) {
        if (cur[0][0][i] == '0') {
            ans.emplace_back(0, 0, 1, 0);
            cur[1][0] += '0';
        }
        else {
            ans.emplace_back(0, 0, 0, 1);
            cur[0][1] += '1';
        }
    }
    cur[0][0].clear();
    int mem = (int)cur[0][1].size() - 1;
    while (mem >= 0 && cur[0][1][mem] == '1') --mem;
    ++mem;
    for (int i = 0; i < mem; ++i) {
        if (cur[0][1][i] == '0') {
            cur[0][0] += '0';
            ans.emplace_back(0, 1, 0, 0);
        }
        else {
            cur[1][1] += '1';
            ans.emplace_back(0, 1, 1, 1);
        }
    }
    cur[0][1].clear();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) continue;
            if (i == 0 && j == 1) continue;
            for (int k = 0; k < cur[i][j].size(); ++k) {
                if (cur[i][j][k] == '0') {
                    if (i == 0 || j == 0) {
                        ans.emplace_back(i, j, 0, 0);
                        cur[0][0] += '0';
                    }
                    else {
                        ans.emplace_back(i, j, i, 0);
                        cur[i][0] += '0';
                    }
                }
                else {
                    if (i == 0 || j == 1) {
                        ans.emplace_back(i, j, 0, 1);
                        cur[0][1] += '1';
                    }
                    else {
                        ans.emplace_back(i, j, i, 1);
                        cur[i][1] += '1';
                    }
                }
            } 
            cur[i][j].clear();
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) continue;
            if (i == 0 && j == 1) continue;
            for (int k = cur[i][j].size() - 1; k >= 0; --k) {
                if (cur[i][j][k] == '0') {
                    if (i == 0 || j == 0) {
                        ans.emplace_back(i, j, 0, 0);
                        cur[0][0] += '0';
                    }
                    else {
                        assert(0);
                    }
                }
                else {
                    if (i == 0 || j == 1) {
                        ans.emplace_back(i, j, 0, 1);
                        cur[0][1] += '1';
                    }
                    else {
                        assert(0);
                    }
                }
            } 
            cur[i][j].clear();
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    vector <vector <string>> start(n, vector <string> (m));
    vector <vector <string>> finish(n, vector <string> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> start[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> finish[i][j];
        }
    }
    vector <turn> ans1 = get(start);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            reverse(finish[i][j].begin(), finish[i][j].end());
        }
    }
    vector <turn> ans2 = get(finish);
    reverse(ans2.begin(), ans2.end()); 
    cout << ans1.size() + ans2.size() << '\n';
    for (auto x : ans1) {
        cout << x.a + 1 << ' ' << x.b + 1 << ' ' << x.c + 1 << ' ' << x.d + 1 << '\n';
    }
    for (auto x : ans2) {
        cout << x.c + 1 << ' ' << x.d + 1 << ' ' << x.a + 1 << ' ' << x.b + 1 << '\n';
    }
}