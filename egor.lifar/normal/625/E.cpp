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
#include <cstring>
#include <cmath>


using namespace std;


#define next next1


struct frog { 
    int p, z, number; 
    frog(){}
    frog(int _p, int _z, int _number) {
        p = _p;
        z = _z;
        number = _number;
    }
};


frog a[100010];
int n, m, pl[100010], next[100010], ans[100010], pref[100010], w[100010]; 
bool c[100010];
long long plusik[100010];
priority_queue<pair<int, int> > q;


bool les(frog x, frog y) { 
    return x.p < y.p; 
}


int when(int x, int k) {
    if (x == k) {
        return 0;
    }
    long long l = a[k].p - a[x].p; 
    if (l <= 0) {
        l = m + l;
    }
    l += plusik[k] - plusik[x];
    int t = 0;
    if (a[x].number < a[k].number) {
        l -= a[x].z;
        t = 1;
    }
    if (l <= 0 && !plusik[x] && !plusik[k]) {
        return 1;
    }
    if (a[k].z < a[x].z) {
        return (l - 1) / (a[x].z - a[k].z) + t + 1;
    }
    return 0;
}


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i].p, &a[i].z);
        a[i].number = i, c[i] = 1;
    }
    sort(a + 1, a + n + 1, les);
    for (int i = 1; i <= n; i++) {
        pl[a[i].number] = i;
    }
    for (int j = 1; j <= n; j++) {
        int i = pl[j];
        int k = i % n + 1;
        int z = when(i, k); 
        next[i] = k;
        pref[k] = i;
        if (z) {
            q.push(make_pair(-z, -j));
            w[i] = z;
        }
    }
    while (!q.empty()) {
        pair<int, int> p = q.top();
        int x = pl[-p.second];
        int z = -p.first;
        int cnt = 1; 
        q.pop();
        if (!c[x] || w[x] != z) {
            continue;
        }
        c[next[x]] = 0;
        next[x] = next[next[x]];
        while (when(x, next[x]) == z) { 
            c[next[x]] = 0;
            next[x] = next[next[x]];
            cnt++;
        }
        a[x].z = max(a[x].z - cnt, 0);
        pref[next[x]] = x;
        plusik[x] += (long long)cnt * z;
        z = when(x, next[x]);
        if (z) {
            q.push(make_pair(-z, -a[x].number));
            w[x] = z;
        } else {
            w[x] = 0;
        }
        z = when(pref[x], x);
        if (z) {
            q.push(make_pair(-z, -a[pref[x]].number));
            w[pref[x]] = z;
        }
    }
    int sz = 0;
    for (int i = 1; i <= n; i++) {
        if (c[i]) {
            sz++;
            ans[sz] = a[i].number;
        }
    }
    cout << sz << endl;
    for (int i = 1; i <= sz; i++) {
        printf("%d ", ans[i]);
    }
    cout << endl;
    return 0;
}