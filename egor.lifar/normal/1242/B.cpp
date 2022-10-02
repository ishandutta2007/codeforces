#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 200228;


int n, m;
vector<int> g[MAXN];
int parent[MAXN];


int findset(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = findset(parent[v]);
}


void merge(int a, int b) {
    a = findset(a);
    b = findset(b);
    parent[a] = b;
}


int kek[MAXN];


void add(int l, int r) {
    kek[l]++;
    kek[r]--;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        sort(all(g[i]));
        int last = 1;
        for (auto h: g[i]) {
            if (last < h) {
                merge(last, i);
                add(last, h - 1);
            }
            last = h + 1;
        }
        if (last < n) {
            merge(last, i);
            add(last, n);
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += kek[i];
        if (sum) {
            merge(i, i + 1);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (auto h: g[i]) {
            if (findset(h) != findset(i)) {
                parent[findset(h)] = findset(i);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}