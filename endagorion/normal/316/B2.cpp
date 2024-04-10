#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

int a[10000], p[10000], l[10000], t[10000];

void count(int x) {
    if (p[x] != -1) {
        return;
    }
    if (a[x] == -1) {
        p[x] = x;
        l[x] = 1;
    } else {
        count(a[x]);
        p[x] = p[a[x]];
        l[x] = l[a[x]] + 1;
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, x;
    cin >> N >> x;
    --x;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        --a[i];
        p[i] = l[i] = -1;
    }
    for (int i = 0; i < N; ++i) {
        count(i);
    }

    for (int i = 0; i < N; ++i) {
        t[p[i]] = max(t[p[i]], l[i]);
    }
    vector<int> seg;
    for (int i = 0; i < N; ++i) {
        if (t[i] > 0 && i != p[x]) {
            seg.pb(t[i]);
        }
    }
    vector< vector<bool> > pos(seg.size() + 1, vector<bool>(N + 1));
    pos[0][0] = true;
    for (int i = 0; i < seg.size(); ++i) {
        for (int j = 0; j < N; ++j) {
            if (pos[i][j]) {
                pos[i + 1][j] = true;
                pos[i + 1][j + seg[i]] = true;
            }
        }
    }

    for (int i = 0; i <= N; ++i) {
        if (pos[seg.size()][i]) {
            cout << i + l[x] << '\n';
        }
    }

	return 0;
}