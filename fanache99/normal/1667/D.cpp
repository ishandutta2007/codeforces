#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

const int MAXN = 200000;

vector<int> g[1 + MAXN];
bool dp[1 + MAXN][2];
bool bad;

void DFS(int node, int father) {
    int onlySame = 0, onlyDiff = 0, sons = 0;
    for (auto son : g[node]) {
        if (son != father) {
            DFS(son, node);
            if (!dp[son][0] && !dp[son][1]) {
                bad = true;
            }
            int e = (g[node].size() + g[son].size()) % 2;
            if (dp[son][e] && !dp[son][e ^ 1]) {
                onlySame++;
            }
            if (dp[son][e ^ 1] && !dp[son][e]) {
                onlyDiff++;
            }
            sons++;
        }
    }

    { // 0 from up
        int same = sons / 2, diff = sons - sons / 2;
        dp[node][0] = (onlySame <= same && onlyDiff <= diff);
    }
    { // 1 from up
        if (sons == 0) {
            dp[node][1] = false;
        } else {
            int same = 1 + (sons - 1) - (sons - 1) / 2, diff = (sons - 1) / 2;
            dp[node][1] = (onlySame <= same && onlyDiff <= diff);
        }
    }
}

int deg[1 + MAXN];

void eliminate(int a, int b) {
    assert((deg[a] + deg[b]) % 2 == 0);
    cout << a << " " << b << "\n";
    deg[a]--;
    deg[b]--;
}

void solve(int node, int father, int up) {
    assert(dp[node][up]);

    vector<int> onlySame, onlyDiff, both;
    int sons = 0;
    for (auto son : g[node]) {
        if (son != father) {
            int e = (g[node].size() + g[son].size()) % 2;
            if (dp[son][e] && !dp[son][e ^ 1]) {
                onlySame.push_back(son);
            } else if (dp[son][e ^ 1] && !dp[son][e]) {
                onlyDiff.push_back(son);
            } else {
                both.push_back(son);
            }
            sons++;
        }
    }

    if (up == 0) {
        eliminate(node, father);
        for (int i = 1; i <= sons; i++) {
            int son;
            if (i % 2 == 1) { // diff
                if (onlyDiff.empty()) {
                    son = both.back();
                    both.pop_back();
                } else {
                    son = onlyDiff.back();
                    onlyDiff.pop_back();
                }
            } else { // same
                if (onlySame.empty()) {
                    son = both.back();
                    both.pop_back();
                } else {
                    son = onlySame.back();
                    onlySame.pop_back();
                }
            }
            int e = (g[node].size() + g[son].size()) % 2;
            if (i % 2 == 1) {
                solve(son, node, e ^ 1);
            } else {
                solve(son, node, e);
            }
        }
    } else {
        assert(sons >= 1);
        int son;
        if (onlySame.empty()) {
            son = both.back();
            both.pop_back();
        } else {
            son = onlySame.back();
            onlySame.pop_back();
        }
        int e = (g[node].size() + g[son].size()) % 2;
        solve(son, node, e);
        eliminate(node, father);
        for (int i = 1; i <= sons - 1; i++) {
            int son;
            if (i % 2 == 1) { // same
                if (onlySame.empty()) {
                    son = both.back();
                    both.pop_back();
                } else {
                    son = onlySame.back();
                    onlySame.pop_back();
                }
            } else { // diff
                if (onlyDiff.empty()) {
                    son = both.back();
                    both.pop_back();
                } else {
                    son = onlyDiff.back();
                    onlyDiff.pop_back();
                }
            }
            int e = (g[node].size() + g[son].size()) % 2;
            if (i % 2 == 1) {
                solve(son, node, e);
            } else {
                solve(son, node, e ^ 1);
            }
        }
    }
}

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto startTime = high_resolution_clock::now();
    srand(time(0));

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        bad = false;
        int root = 1;
        DFS(root, 0);

        int onlySame = 0, onlyDiff = 0, sons = 0;
        for (auto son : g[root]) {
            if (!dp[son][0] && !dp[son][1]) {
                bad = true;
            }
            int e = (g[root].size() + g[son].size()) % 2;
            if (dp[son][e] && !dp[son][e ^ 1]) {
                onlySame++;
            }
            if (dp[son][e ^ 1] && !dp[son][e]) {
                onlyDiff++;
            }
            sons++;
        }

        int same = sons - sons / 2, diff = sons / 2;
        bool good = (onlySame <= same && onlyDiff <= diff);
        if (!good) {
            bad = true;
        }

        if (bad) {
            cout << "NO\n";
        } else {
            cout << "YES\n";

            for (int i = 1; i <= n; i++) {
                deg[i] = g[i].size() % 2;
            }

            vector<int> onlySame, onlyDiff, both;
            int sons = 0;
            for (auto son : g[root]) {
                int e = (g[root].size() + g[son].size()) % 2;
                if (dp[son][e] && !dp[son][e ^ 1]) {
                    onlySame.push_back(son);
                } else if (dp[son][e ^ 1] && !dp[son][e]) {
                    onlyDiff.push_back(son);
                } else {
                    both.push_back(son);
                }
                sons++;
            }

            for (int i = 1; i <= sons; i++) {
                int son;
                if (i % 2 == 1) { // same
                    if (onlySame.empty()) {
                        son = both.back();
                        both.pop_back();
                    } else {
                        son = onlySame.back();
                        onlySame.pop_back();
                    }
                } else {
                    if (onlyDiff.empty()) {
                        son = both.back();
                        both.pop_back();
                    } else {
                        son = onlyDiff.back();
                        onlyDiff.pop_back();
                    }
                }
                int e = (g[root].size() + g[son].size()) % 2;
                if (i % 2 == 1) {
                    solve(son, root, e);
                } else {
                    solve(son, root, e ^ 1);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}