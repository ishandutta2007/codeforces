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

const int MAXN = 500000;
const long long INF = 1e18;

int a[4][1 + MAXN];
long long sum[4][1 + MAXN];
long long pref[1 + MAXN], suff[1 + MAXN];
vector<pair<int, int>> endsAt[1 + MAXN];

struct Node {
    long long bestPref;
    long long bestSuff;
    long long best;
};
Node tree[1 + 4 * MAXN];

void build(int node, int left, int right) {
    if (left == right) {
        tree[node].bestPref = pref[left];
        tree[node].bestSuff = suff[left];
        tree[node].best = tree[node].bestPref + tree[node].bestSuff;
        return;
    }
    int middle = (left + right) / 2;
    build(2 * node, left, middle);
    build(2 * node + 1, middle + 1, right);
    tree[node].bestPref = max(tree[2 * node].bestPref, tree[2 * node + 1].bestPref);
    tree[node].bestSuff = max(tree[2 * node].bestSuff, tree[2 * node + 1].bestSuff);
    tree[node].best = max(max(tree[2 * node].best, tree[2 * node + 1].best), tree[2 * node].bestPref + tree[2 * node + 1].bestSuff);
}

void update(int node, int left, int right, int where, long long val) {
    if (left == right) {
        tree[node].bestPref = max(tree[node].bestPref, val);
        tree[node].best = tree[node].bestPref + tree[node].bestSuff;
        return;
    }
    int middle = (left + right) / 2;
    if (where <= middle) {
        update(2 * node, left, middle, where, val);
    } else {
        update(2 * node + 1, middle + 1, right, where, val);
    }
    tree[node].bestPref = max(tree[2 * node].bestPref, tree[2 * node + 1].bestPref);
    tree[node].bestSuff = max(tree[2 * node].bestSuff, tree[2 * node + 1].bestSuff);
    tree[node].best = max(max(tree[2 * node].best, tree[2 * node + 1].best), tree[2 * node].bestPref + tree[2 * node + 1].bestSuff);
}

Node answer;

void query(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        answer.best = max(max(answer.best, tree[node].best), answer.bestPref + tree[node].bestSuff);
        answer.bestPref = max(answer.bestPref, tree[node].bestPref);
        answer.bestSuff = max(answer.bestSuff, tree[node].bestSuff);
        return;
    }
    int middle = (left + right) / 2;
    if (from <= middle) {
        query(2 * node, left, middle, from, to);
    }
    if (middle + 1 <= to) {
        query(2 * node + 1, middle + 1, right, from, to);
    }
}

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int r = 1; r <= 3; r++) {
        for (int i = 1; i <= n; i++) {
            cin >> a[r][i];
            sum[r][i] = a[r][i] + sum[r][i - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        pref[i] = sum[1][i] - sum[2][i - 1];
        suff[i] = sum[2][i] + sum[3][n] - sum[3][i - 1];
    }
    build(1, 1, n);
    long long ans = -INF;
    for (int i = 1; i <= q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        endsAt[r].emplace_back(l, k);
    }
    for (int r = 1; r <= n; r++) {
        for (auto &[l, k] : endsAt[r]) {
            answer = {-INF, -INF, -INF};
            query(1, 1, n, l, r);
            ans = max(ans, answer.best - k);
            if (r != n) {
                update(1, 1, n, r + 1, answer.bestPref - k);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}