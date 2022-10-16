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

const int MAXN = 1000;
const int MOD = 998244353;

long long v[1 + MAXN];
vector<int> g[1 + MAXN], gt[1 + MAXN];
int deg[1 + MAXN], nodes[1 + MAXN];

void sortTop(int n) {
    int left = 1, right = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            right++;
            nodes[right] = i;
        }
    }
    while (left <= right) {
        int node = nodes[left];
        left++;
        for (auto it : g[node]) {
            deg[it]--;
            if (deg[it] == 0) {
                right++;
                nodes[right] = it;
            }
        }
    }
}

bool simulate(int n) {
    bool all0 = true;
    for (int i = n; i >= 1; i--) {
        int node = nodes[i];
        if (v[node] != 0) {
            all0 = false;
            v[node]--;
            for (auto it : g[node]) {
                v[it]++;
            }
        }
    }
    return !all0;
}

int cnt[1 + MAXN];

int getAns(int n) {
    cnt[nodes[n]] = 1;
    int ans = v[nodes[n]] % MOD;
    for (int i = n - 1; i >= 1; i--) {
        int node = nodes[i];
        cnt[node] = 0;
        for (auto it : g[node]) {
            cnt[node] = (cnt[node] + cnt[it]) % MOD;
        }
        ans = (1LL * cnt[node] * v[node] + ans) % MOD;
    }
    return ans;
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
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            gt[b].push_back(a);
            deg[b]++;
        }

        sortTop(n);
        int limit = 2 * n;
        bool done = false;
        for (int i = 1; i <= limit; i++) {
            if (!simulate(n)) {
                done = true;
                cout << i - 1 << "\n";
                break;
            }
        }
        if (!done) {
            cout << (getAns(n) + limit) % MOD << "\n";
        }

        for (int i = 1; i <= n; i++) {
            g[i].clear();
            gt[i].clear();
            deg[i] = 0;
        }
    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}