#pragma comment(linker, "/STACK:512000000")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <numeric>
#include <ctime>
#include <cassert>
#include <bitset>
#include <cmath>
#include <queue>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define for1(i, n) for (int i = 1; i <= int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

using namespace std;

typedef long long i64;
typedef unsigned long long ui64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef long double ld;

const int MAXL = 1000000;
char buf[MAXL];
int nxt[MAXL][26];
vi spec[2][MAXL];
int tc = 0;

int lnxt[2 * MAXL], lid[2 * MAXL];
int ans[MAXL];
int total = 0;

int newNode() {
    int node = tc++;
    forn(i, 26) nxt[node][i] = -1;
    return node;
}

int add(int root, const string &s) {
    for (char c: s) {   
        int i = c - 'a';
        if (nxt[root][i] == -1) nxt[root][i] = newNode();
        root = nxt[root][i];
    }
    return root;
}

void rec(int v, int d, int &h1, int &t1, int &h2, int &t2) {
    if (v == -1) return;
    forn(c, 26) {
        int hh1 = -1, tt1 = -1, hh2 = -1, tt2 = -1;
        rec(nxt[v][c], d + 1, hh1, tt1, hh2, tt2);
        if (hh1 != -1) {
            if (h1 == -1) h1 = hh1;
            if (t1 != -1) lnxt[t1] = hh1;
            t1 = tt1;
        }
        if (hh2 != -1) {
            if (h2 == -1) h2 = hh2;
            if (t2 != -1) lnxt[t2] = hh2;
            t2 = tt2;
        }
    }
    forn(j, 2) for (int x: spec[j][v]) {
        int &h = j ? h2 : h1, &t = j ? t2 : t1;
        if (h == -1) h = t = x;
        else lnxt[t] = x, t = x;
    }
    while (h1 != -1 && h2 != -1) {
        total += d;
        ans[lid[h1]] = lid[h2];
        h1 = lnxt[h1];
        h2 = lnxt[h2];
    }
    if (h1 == -1) t1 = -1;
    if (h2 == -1) t2 = -1;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;

    int root = newNode();
    int N;
    scanf("%d", &N);
    int z = 0;
    forn(j, 2) forn(i, N) {
        scanf("%s", buf);
        string name = buf;
        int n = add(root, name);
        lnxt[z] = -1;
        lid[z] = i;
        spec[j][n].pb(z++);
    }
    int h1 = -1, t1 = -1, h2 = -1, t2 = -1;
    rec(root, 0, h1, t1, h2, t2);
    printf("%d\n", total);
    forn(i, N) printf("%d %d\n", i + 1, ans[i] + 1);

    return 0;
}