#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;




int n;
int a[1000001];
int d[2097152];
unordered_map<int, int> t;
vector<int> v[1000001];
int m;
vector<pair<int, int> > queries[1000001];
int ans[1000001];
int dd[1000001];


void change(int i, int x) {
    d[i] = x;
    while (i / 2 > 0) {
        i /= 2;
        d[i] = d[i * 2] ^ d[i * 2 + 1];
    }
}


int rmq(int v, int vl, int vr, int l, int r) {
    if (vl > r || vr < l) {
        return 0;
    }
    if (l <= vl && vr <= r) {
        return d[v];
    }
    return rmq(v * 2, vl, (vl + vr) / 2, l, r) ^ rmq(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r);
}


int main() {
    cin >> n;
    int ss = 1;
    while (ss < n) {
        ss *= 2;
    }   
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        v[t[a[i]]].push_back(i);
        t[a[i]] = i + 1;
        dd[i] = a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--;
        r--;
        queries[l].push_back(make_pair(r, i));
    }
    for (int i = 1; i < n; i++) {
        dd[i] ^= dd[i - 1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)v[i].size(); j++) {
            change(ss + v[i][j], a[v[i][j]]);
        }
        for (int j = 0; j < (int)queries[i].size(); j++) {
            ans[queries[i][j].second] = rmq(1, 1, ss, i + 1, queries[i][j].first + 1);
            ans[queries[i][j].second] ^= dd[queries[i][j].first] ^ (i != 0 ? dd[i - 1]: 0);
        }
    }
    for (int i = 0; i < m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}