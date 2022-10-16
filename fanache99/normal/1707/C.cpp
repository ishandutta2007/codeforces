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

const int MAXN = 100000;

int v[1 + MAXN];
int dad[1 + MAXN];
vector<int> g[1 + MAXN];
vector<pair<int, int>> bad;

int findDad(int node) {
    if (node == dad[node]) {
        return node;
    }
    return dad[node] = findDad(dad[node]);
}

void join(int a, int b) {
    a = findDad(a), b = findDad(b);
    if (rand() % 2) {
        dad[a] = b;
    } else {
        dad[b] = a;
    }
}

int first[1 + MAXN], last[1 + MAXN], depth[1 + MAXN], cnt = 0;
int up[1 + MAXN][20];

void DFS1(int node, int father) {
    depth[node] = depth[father] + 1;
    cnt++;
    first[node] = cnt;
    up[node][0] = father;
    for (int i = 1; i < 20; i++) {
        up[node][i] = up[up[node][i - 1]][i - 1];
    }
    for (auto son : g[node]) {
        if (son != father) {
            DFS1(son, node);
        }
    }
    last[node] = cnt;
}

int raise(int node, int delta) {
    for (int i = 0; i < 20; i++) {
        if ((delta >> i) & 1) {
            node = up[node][i];
        }
    }
    return node;
}

int good[1 + MAXN], add = 0;
char s[1 + MAXN + 1];

void DFS2(int node, int father, int sum) {
    sum += good[node];
    if (sum == bad.size()) {
        s[node] = '1';
    } else {
        s[node] = '0';
    }
    for (auto son : g[node]) {
        if (son != father) {
            DFS2(son, node, sum);
        }
    }
}

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto startTime = high_resolution_clock::now();
    srand(time(0));

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dad[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (findDad(a) != findDad(b)) {
            join(a, b);
            g[a].push_back(b);
            g[b].push_back(a);
        } else {
            bad.emplace_back(a, b);
        }
    }
    DFS1(1, 0);
    for (auto [a, b]: bad) {
        if (depth[a] > depth[b]) {
            swap(a, b);
        }
        if (first[a] <= first[b] && last[b] <= last[a]) {
            good[b]++;
            add++;
            int c = raise(b, depth[b] - depth[a] - 1);
            good[c]--;
        } else {
            good[a]++;
            good[b]++;
        }
    }
    DFS2(1, 0, add);
    s[n + 1] = 0;
    cout << (s + 1) << "\n";

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}