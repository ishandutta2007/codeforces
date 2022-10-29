#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
const int N = 500005;
int n, a[N], b[N], id[N];
std::vector<int> el[N], er[N];
std::set<int> s;
std::map<int,int> m;

void inc(int l) {
    ++m[l];
}

void dec(int l) {
    if (!--m[l])
        m.erase(l);
}

int max_length() {
    return m.rbegin()->first;
}

void add(int p) {
    auto it = s.upper_bound(p);
    int r = *it, l = *--it;
    s.insert(p);
    dec(r - l);
    inc(p - l);
    inc(r - p);
}

void del(int p) {
    if (p == 1 || p == (n + 1))
        return;
    s.erase(p);
    auto it = s.upper_bound(p);
    int r = *it, l = *--it;
    dec(p - l);
    dec(r - p);
    inc(r - l);
}

void update(int p, int x) {
    if (p < 1 || n < p)
        return;
    auto it = s.upper_bound(p);
    int r = *it - 1, l = *--it;
    if (b[l] && b[r]) {
        // do nothing
    } else if (b[l]) {
        el[(l + r + 1) / 2].push_back(x);
        er[r].push_back(x);
    } else if (b[r]) {
        el[l].push_back(x);
        er[(l + r - 1) / 2].push_back(x);
    } else {
        el[l].push_back(x);
        er[r].push_back(x);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    // -------- init ----------
    for (int i = 1; i <= n; ++i)
        b[i] = 1;
    for (int i = 1; i <= n + 1; ++i)
        s.insert(i);
    m[1] = n;
    for (int i = 1; i <= n; ++i)
        id[i] = i;
    std::sort(id + 1, id + n + 1, [](int x, int y){
        return a[x] < a[y];
    });
    // ------------------------
    int max = 0;
    for (int i = 1; i <= n; ++i) {
        int p = id[i];
        b[p] = 0;
        auto it = s.upper_bound(p);
        int r = *it, l = *--it;
        bool fl = l == p, fr = r == p + 1;
        if (fl && fr) {
            del(p);
            del(p + 1);
            update(p, i);
        } else if (fl) {
            del(p);
            add(p + 1);
            update(p, i);
            update(p + 1, i);
        } else if (fr) {
            add(p);
            del(p + 1);
            update(p, i);
            update(p - 1, i);
        } else {
            add(p);
            add(p + 1);
            update(p, i);
            update(p - 1, i);
            update(p + 1, i);
        }
        if (i == n || a[id[i]] < a[id[i + 1]])
            max = std::max(max, max_length());
    }
    printf("%d\n", (max - 1) / 2);
    std::set<int> s;
    for (int i = 1; i <= n; ++i) {
        for (int x : el[i])
            s.insert(x);
        printf("%d ", a[id[*s.begin()]]);
        for (int x : er[i])
            s.erase(x);
    }
    printf("\n");
}