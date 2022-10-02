#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>


using namespace std;


int n, m;
vector<int> g[200001];
int a[200001];
int b[200001];
int cnt[200001];



bool get(int x) {
    set<pair<int, int> > k;
    for (int i = 0; i < n; i++) {
        g[i].clear();
        cnt[i] = 0;
    }
    for (int i = 0; i < x; i++) {
        g[b[i]].push_back(a[i]);
        cnt[a[i]]++;
    }   
    for (int i = 0; i < n; i++) {
        k.insert(make_pair(cnt[i], i));
    }
    while (!k.empty()) {
        pair<int, int> t = *k.begin();
        k.erase(t);
        if (!k.empty() && (*k.begin()).first == 0) {
            return 0;
        }
        for (int i = 0; i < (int)g[t.second].size(); i++) {
            int h = g[t.second][i];
            k.erase(make_pair(cnt[h], h));
            cnt[h]--;
            k.insert(make_pair(cnt[h], h));
        }
    }
    return 1;
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a[i], &b[i]);
        a[i]--;
        b[i]--;
    }
    if (!get(m)) {
        cout << -1 << endl;
        return 0;
    }
    int l = 1;
    int r = m;
    while (l != r) {
        int k = (l + r) / 2;
        if (get(k)) {
            r = k;
        } else {
            l = k + 1;;
        }
    }
    cout << l << endl;
    return 0;
}