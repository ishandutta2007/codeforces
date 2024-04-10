#include <bits/stdc++.h>
#define MN 2000010

using namespace std;

int n, a[MN], b[MN], rev[MN], SZ, co;
vector<int> ys;

int parent[MN], cv[MN], ce[MN], m1[MN], m2[MN];

int find(int no) {
    if(no == parent[no]) return no;
    return parent[no] = find(parent[no]);
}

void join(int a, int b) {
    a = find(a); b = find(b);
    if(a == b) return;
    if(cv[a] > cv[b]) {
        parent[b] = a;
        cv[a] += cv[b];
        ce[a] += ce[b];

        if(m1[b] > m1[a]) {
            m2[a] = max(m1[a], m2[b]);
            m1[a] = m1[b];
        } else {
            m2[a] = max(m2[a], m1[b]);
        }

    } else {
        parent[a] = b;
        cv[b] += cv[a];
        ce[b] += ce[a];

        if(m1[a] > m1[b]) {
            m2[b] = max(m1[b], m2[a]);
            m1[b] = m1[a];
        } else {
            m2[b] = max(m2[b], m1[a]);
        }
    }
}

int ok() {
    for(int i = 1; i < SZ; i++) {
        parent[i] = i;
        cv[i] = 1;
        ce[i] = 0;
        m1[i] = i;
        m2[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        join(a[i], b[i]);
        ce[find(a[i])]++;
    }

    int ret = 0;
    for(int i = 1; i < SZ; i++) {
        if(find(i) != i) continue;
        if(ce[i] == cv[i]) ret = max(ret, m1[i]);
        else if(ce[i] < cv[i]) ret = max(ret, m2[i]);
        else return -1;
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        ys.push_back(a[i]);
        ys.push_back(b[i]);
    } {
        sort(ys.begin(), ys.end());
        ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
        for(int i = 0; i < n; i++) {
            int qa = lower_bound(ys.begin(), ys.end(), a[i]) - ys.begin() + 1;
            int qb = lower_bound(ys.begin(), ys.end(), b[i]) - ys.begin() + 1;
            rev[qa] = a[i];
            rev[qb] = b[i];
            a[i] = qa;
            b[i] = qb;
        }
        SZ = ys.size() + 1;
    }

    int ans = ok();

    if(ans == -1) puts("-1");
    else printf("%d\n", rev[ans]);
    return 0;
}