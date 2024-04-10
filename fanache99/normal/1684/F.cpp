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

int v[1 + MAXN];
vector<int> add[1 + MAXN], erase[1 + MAXN], where[1 + MAXN];
int leftmost[1 + MAXN], last[1 + MAXN], leftEnd[1 + MAXN];

void normalize(int n) {
    map<int, int> f;
    for (int i = 1; i <= n; i++) {
        f[v[i]] = 1;
    }
    int m = 0;
    for (auto &it : f) {
        it.second = ++m;
    }
    for (int i = 1; i <= n; i++) {
        v[i] = f[v[i]];
    }
}

bool check(int l, int n) {
    for (int i = 1; i <= n; i++) {
        last[i] = 0;
        where[i].clear();
    }
    int prefix = 0, suffix = 0;
    for (int i = 1; i <= n; i++) {
        if (last[v[i]] >= leftmost[i]) {
            if (prefix == 0) {
                prefix = i;
            }
            suffix = max(suffix, last[v[i]]);
        }
        last[v[i]] = i;
        where[v[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        leftEnd[i] = 0;
        reverse(where[i].begin(), where[i].end());
    }

    int bad = 0;
    for (int i = l; i <= n; i++) {
        if (i != l) {
            if (leftEnd[i] >= leftmost[i]) {
                bad--;
            }
            if (leftEnd[i] != 0) {
                int y = v[leftEnd[i]];
                while (!where[y].empty() && where[y].back() <= i) {
                    where[y].pop_back();
                }
                if (!where[y].empty()) {
                    int j = where[y].back();
                    if (leftEnd[j] < leftmost[j] && leftEnd[i] >= leftmost[j]) {
                        bad++;
                    }
                    leftEnd[j] = leftEnd[i];
                }
            }

            int x = v[i - l];
            while (!where[x].empty() && where[x].back() <= i) {
                where[x].pop_back();
            }
            if (!where[x].empty()) {
                int j = where[x].back();
                if (leftEnd[j] < leftmost[j] && i - l >= leftmost[j]) {
                    bad++;
                }
                leftEnd[j] = i - l;
            }
        }
        if (bad == 0 && i - l + 1 <= prefix && i >= suffix) {
            return true;
        }
    }
    return false;
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
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        normalize(n);
        for (int i = 1; i <= m; i++) {
            int l, r;
            cin >> l >> r;
            add[l].push_back(l);
            erase[r].push_back(l);
        }
        multiset<int> leftEnds;
        for (int i = 1; i <= n; i++) {
            for (auto l : add[i]) {
                leftEnds.insert(l);
            }
            leftmost[i] = (leftEnds.empty() ? n + 1 : *leftEnds.begin());
            for (auto l : erase[i]) {
                auto it = leftEnds.find(l);
                assert(it != leftEnds.end());
                leftEnds.erase(it);
            }
            add[i].clear();
            erase[i].clear();
            last[i] = 0;
        }
        bool found = false;
        for (int i = 1; i <= n; i++) {
            if (last[v[i]] >= leftmost[i]) {
                found = true;
            }
            last[v[i]] = i;
        }
        if (!found) {
            cout << "0\n";
        } else {
            int left = 1, right = n, ans = n;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (check(mid, n)) {
                    ans = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            cout << ans << "\n";
        }
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}