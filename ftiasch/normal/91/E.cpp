// Codeforces Beta Round #75
// Problem E -- Igloo Skyscraper
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 111111;

int n, q, a[N], b[N];
vector<int> tree[N << 2];

bool cmp (int i, int j) {
    if (b[i] == b[j]) {
        return a[i] > a[j];
    }
    return b[i] < b[j];
}

double intersect (int i, int j) { // x-coordinate
    return -(double)(a[i] - a[j]) / (b[i] - b[j]);
}

void build (int t, int l, int r) { 
    vector<int> ord;
    ord.clear();
    for (int i = l; i <= r; ++ i) {
        ord.push_back(i);
    }
    sort(ord.begin(), ord.end(), cmp);
    vector<int> &res = tree[t];
    res.clear();
    for (int i = 0; i < (int)ord.size(); ++ i) {
        if (res.size() and b[res.back()] == b[ord[i]]) {
            continue;
        }
        while ((int)res.size() > 1 and 
                intersect(res[res.size() - 2], ord[i]) 
                >= intersect(res[res.size() - 1], ord[i])) {
            res.pop_back();
        }
        res.push_back(ord[i]);
    }
    if (r > l) {
        int m = (l + r) >> 1;
        build(t + t, l, m);
        build(t + t + 1, m + 1, r);
    }
}

int getMax (int i, int j, int x) {
    if (a[i] + (long long)b[i] * x > 
            a[j] + (long long)b[j] * x) {
        return i;
    } 
    return j;
}

int query(int t, int l, int r, int a, int b, int x) {
    if (b < l or r < a) {
        return 0;
    }      
    if (a <= l and r <= b) {
        vector<int> &res = tree[t];
        if ((int)res.size() == 1) {
            return res[0];
        }
        if (x <= intersect(res[0], res[1])) {
            return res[0];
        }
        int lower = 1, upper = (int)res.size() - 1;
        while (lower < upper) {
            int mider = (lower + upper + 1) >> 1;
            if (intersect(res[mider - 1], res[mider]) <= x) {             
                lower = mider;
            } else {
                upper = mider - 1;
            }
        }
        return res[lower];
    }
    int m = (l + r) >> 1;
    return getMax(query(t + t, l, m, a, b, x), 
            query(t + t + 1, m + 1, r, a, b, x), x);
}

int main () {
    scanf("%d%d", &n, &q);
    a[0] = b[0] = 0;
    for (int i = 1; i <= n; ++ i) {
        scanf("%d%d", a + i, b + i);
    }
    build(1, 1, n);
    while (q --) {
        int l, r, t;
        scanf("%d%d%d", &l, &r, &t);
        printf("%d\n", query(1, 1, n, l, r, t));
    }
    return 0;
}