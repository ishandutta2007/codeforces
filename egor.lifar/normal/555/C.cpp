#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;


int INF = 1000 * 1000 * 1000 + 1;


int n, q;
string s[200000];
int x[200000];
int y[200000];
map<int, int> mx, my;
pair<int, int> dx[1000000], dy[1000000];
int ss;
map<int, bool> mm;


void change(int i, int x) {
    dx[i] = make_pair(x, -(i - ss + 1));
    while (i / 2 > 0) {
        i /= 2;
        dx[i] = min(dx[i * 2], dx[i * 2 + 1]);
    }
}


void change1(int i, int x) {
    dy[i] = make_pair(x, -(i - ss + 1));
    while (i / 2 > 0) {
        i /= 2;
        dy[i] = min(dy[i * 2], dy[i * 2 + 1]);
    }
}


int spusk(int v, int vl, int vr, int r, int x) {
    if (vl > r) {
        return -1;
    }
    if (vr <= r) {
        if (dx[v].first > x) {
            return -1;
        }
        if (vl == vr) {
            return vl;
        }
        int vm = (vl + vr) / 2;
        if (dx[v * 2 + 1].first <= x) {
            return spusk(v * 2 + 1, vm + 1, vr, r, x);
        }
        return spusk(v * 2, vl, vm, r, x);
    }
    int vm = (vl + vr) / 2;
    int ans = spusk(v * 2 + 1, vm + 1, vr, r, x);
    if (ans != -1) {
        return ans;
    }
    return spusk(v * 2, vl, vm, r, x);
}


int spusk1(int v, int vl, int vr, int r, int x) {
    if (vl > r) {
        return -1;
    }
    if (vr <= r) {
        if (dy[v].first > x) {
            return -1;
        }
        if (vl == vr) {
            return vl;
        }
        int vm = (vl + vr) / 2;
        if (dy[v * 2 + 1].first <= x) {
            return spusk1(v * 2 + 1, vm + 1, vr, r, x);
        }
        return spusk1(v * 2, vl, vm, r, x);
    }
    int vm = (vl + vr) / 2;
    int ans = spusk1(v * 2 + 1, vm + 1, vr, r, x);
    if (ans != -1) {
        return ans;
    }
    return spusk1(v * 2, vl, vm, r, x);
}


int main() {
    cin >> n >> q;
    vector<int> xx, yy;
    for (int i = 0; i < q; i++) {
        cin >> x[i] >> y[i] >> s[i];
        xx.push_back(x[i]);
        yy.push_back(y[i]);
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    xx.resize(distance(xx.begin(), unique(xx.begin(), xx.end())));
    yy.resize(distance(yy.begin(), unique(yy.begin(), yy.end())));
    ss = 1;
    while (ss < (int)xx.size()) {
        ss*= 2;
    }
    for (int i = 0; i < ss; i++) {
        change(ss + i, INF);
        change1(ss + i, INF);
    }
    for (int i = 0; i < (int)xx.size(); i++) {
        mx[xx[i]] = i;
        my[yy[i]] = i;
        change(ss + i, yy[(int)xx.size() - i - 1]);
        change1(ss + i, xx[(int)yy.size() - i - 1]);
    }
    for (int i = 0; i < q; i++) {
        if (mm[x[i]]) {
            cout << 0 << endl;
            continue;
        }
        mm[x[i]] = true;
        if (s[i] == "U") {
            int ans;
            if (my[y[i]] == 0) {
                ans = -2;
            } else {
                ans = spusk1(1, 1, ss, my[y[i]], x[i]) - 1;
            }
            int g = 0;
            if (ans == -2) {
                g = 0;
            } else {
                g = yy[ans];
            }
            cout << y[i] - g << endl;
            change(ss + mx[x[i]], g + 1);
          //  change1(ss + my[y[i]], )
        } else {
            int ans;
            if (mx[x[i]] == 0) {
                ans = -2;
            } else {
                ans = spusk(1, 1, ss, mx[x[i]], y[i]) - 1;
            }
            int g1 = 0;
            if (ans == -2) {
                g1 = 0;
            } else {
                g1 = xx[ans];
            }            
            cout << x[i] - g1 << endl;
            change1(ss + my[y[i]], g1 + 1);
        }
    }
    return 0;
}