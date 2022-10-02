#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;


int n;
map<int, int> m;
vector<int> c;


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        c.push_back(x);
    }
    m.clear();
    for (int i = 0; i < n; i++) {
        m[c[i]] = 1;
    }
    int cnt = -1;
    while (true) {
        cnt += 1;
        bool good = true;
        int mx = m.rbegin()->first;
        if (mx <= 1) {
            break;
        }
        m.erase(mx);
        m[mx / 2] += 1;
        set<int> q;
        q.insert(mx / 2);
        while (!q.empty()) {
            int next = *(q.rbegin());
            q.erase(next);
            int u = m[next];
            if (u == 1) {
                continue;
            }
            if (next <= 1) {
                good = false;
                break;
            }
            m[next / 2] += u - 1;
            m[next] = 1;
            q.insert(next / 2);
        }
        if (!good) {
            break;
        }
    }
    m.clear();
    for (int i = 0; i < n; i++) {
        m[c[i]] = 1;
    }
    for (int ii = 0; ii < cnt; ii++) {
        bool good = true;
        int mx = m.rbegin()->first;
        if (mx <= 1) {
            break;
        }
        m.erase(mx);
        m[mx / 2] += 1;
        set<int> q;
        q.insert(mx / 2);
        while (!q.empty()) {
            int next = *(q.rbegin());
            q.erase(next);
            int u = m[next];
            if (u == 1) {
                continue;
            }
            if (next <= 1) {
                good = false;
                break;
            }
            m[next / 2] += u - 1;
            m[next] = 1;
            q.insert(next / 2);
        }
        if (!good) {
            break;
        }
    }
    for (const auto &p : m) {
        printf("%d ", p.first);
    }
    printf("\n");
    return 0;
}