#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>


using namespace std;


int n;
int l[100000], vv[100000], r[100000];
int x[100000], y[100000], x2[100000], y2[100000];
pair<int, int> d[5000001];
int mod[2000001];
int ss = 1;


void change(int i, int x) {
    d[i].first = x;
    while (i / 2 > 0) {
        i /= 2;
        d[i] = max(d[i * 2], d[i * 2 + 1]);
    }
}


void push(int v) {
    if (mod[v] != 0) {
        d[v].first += mod[v];
        mod[v * 2] += mod[v];
        mod[v * 2 + 1] += mod[v];
        mod[v] = 0;
    }
}


pair<int, int> rmq(int v, int l, int r, int vl, int vr) {
    if (vl > r || vr < l) {
        push(v);
        return make_pair(-1, -1);
    }
    if (l <= vl && vr <= r) {
        push(v);
        return d[v];
    }
    push(v);
    pair<int, int> ans = max(rmq(v * 2, l, r, vl, (vl + vr) / 2), rmq(v * 2 + 1, l, r, (vl + vr) / 2 + 1, vr));
    d[v] = max(d[v * 2], d[v * 2 + 1]);
    return ans;
}


void add(int v, int l, int r, int vl, int vr, int x) {
    if (vl > r || vr < l) {
        push(v);
        return;
    }
    if (l <= vl && vr <= r) {
        mod[v] += x;
      //  cout << vl << ' ' << vr << endl;
        push(v);
        return;
    }
    push(v);
    add(v * 2, l, r, vl, (vl + vr) / 2, x);
    add(v * 2 + 1, l, r, (vl + vr) / 2 + 1, vr, x);
    d[v] = max(d[v * 2], d[v * 2 + 1]);
}


vector<int> v[300001];


int main() {
   	cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &l[i], &vv[i], &r[i]);
        x[i] = l[i];
        x2[i] = vv[i];
        y[i] = vv[i];
        y2[i] = r[i];
        v[x[i]].push_back(i + 1);
        v[x2[i] + 1].push_back(-i - 1);
    }
    while (ss < 300000) {
        ss *= 2;
    } 
    for (int i = 1; i <= ss; i++) {
        d[ss + i - 1].second = i;
    }
    for (int i = 1; i <= ss; i++) {
        change(ss + i - 1, 0);
    }
    pair<int, pair<int, int> > ans = make_pair(0, make_pair(0, 0));
    for (int i = 1; i <= 300000; i++) {
        for (int j = 0; j < (int)v[i].size(); j++) {
            int h = v[i][j];
            if (h >= 0) {
          //     cout << y[h] << ' ' << y2[h] << endl;
                add(1, y[h - 1], y2[h - 1], 1, ss, 1);
            } else {
              //   cout << y[-h] << ' ' << y2[-h] << endl;
              //  cout << rmq(1, 1, ss, 1, ss).first << endl;
                add(1, y[-h - 1], y2[-h - 1], 1, ss, -1);
            }
        }
        pair<int, int> p = rmq(1, 1, ss, 1, ss);
       // if (p.first == 2) {
            //cout << p.first << endl;
       // }
        ans = max(ans, make_pair(p.first, make_pair(i, p.second)));
    }
    cout << ans.first << endl;
    //cout << ans.second.first << ' ' << ans.second.second << endl;
    for (int i = 0; i < n; i++) {
        if (ans.second.first >= x[i] && ans.second.first <= x2[i]) {
            if (ans.second.second >= y[i] && ans.second.second <= y2[i]) {
                printf("%d ", i + 1);
            }
        }
    }
    printf("\n");
    return 0;
}