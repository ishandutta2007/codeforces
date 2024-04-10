#include <bits/stdc++.h>
using namespace std;
struct node {
    int tag;
    vector < pair <int, int> > value;
} t[600010];
int n, m, p, k;
inline void down(int x, int l, int r) {
    if(t[x].tag) {
        int mid = l + r >> 1;
        t[x << 1].tag = 1;
        t[x << 1 | 1].tag = 1;
        t[x << 1].value = t[x].value;
        t[x << 1].value[0].second = mid - l + 1;
        t[x << 1 | 1].value = t[x].value;
        t[x << 1 | 1].value[0].second = r - mid;
        t[x].tag = 0;
    }
}
inline vector < pair <int, int> > merge(vector < pair <int, int> > x, vector < pair <int, int> > y) {
    vector < pair <int, int> > ans = x;
    for(auto i : y) {
        int tag = 0;
        for(auto &j : ans) if(j.first == i.first) {
            j.second += i.second;
            tag = 1;
            sort(ans.begin(), ans.end(), [](pair <int, int> a, pair <int, int> b) {
                return a.second > b.second;
            });
            break;
        }
        if(!tag) {
            if(ans.size() < k) {
                ans.push_back(i);
                sort(ans.begin(), ans.end(), [](pair <int, int> a, pair <int, int> b) {
                    return a.second > b.second;
                });
            }
            else if(i.second < ans.back().second) {
                for(auto &j : ans) j.second -= i.second;
            }
            else {
                int tmp = ans.back().second;
                ans.pop_back();
                ans.push_back(i);
                for(auto &j : ans) j.second -= tmp;
                sort(ans.begin(), ans.end(), [](pair <int, int> a, pair <int, int> b) {
                    return a.second > b.second;
                });
            }
        }
    }
    return ans;
}
inline void modify(int x, int l, int r, int L, int R, int val) {
    if(l > R || L > r) return;
    if(L <= l && r <= R) {
        t[x].tag = 1;
        t[x].value.clear();
        t[x].value.push_back(make_pair(val, r - l + 1));
        return;
    }
    int mid = l + r >> 1;
    down(x, l, r);
    modify(x << 1, l, mid, L, R, val);
    modify(x << 1 | 1, mid + 1, r, L, R, val);
    t[x].value = merge(t[x << 1].value, t[x << 1 | 1].value);
}
vector < pair <int, int> > ans;
inline void query(int x, int l, int r, int L, int R) {
    if(l == L && r == R) return void(ans = merge(ans, t[x].value));
    int mid = l + r >> 1;
    down(x, l, r);
    if(R <= mid) query(x << 1, l, mid, L, R);
    else if(L > mid) query(x << 1 | 1, mid + 1, r, L, R);
    else query(x << 1, l, mid, L, mid), query(x << 1 | 1, mid + 1, r, mid + 1, R);
}
int a[150010];
inline void build(int x, int l, int r) {
    if(l == r) {
        t[x].value.clear();
        t[x].value.push_back(make_pair(a[l], 1));
        return;
    }
    int mid = l + r >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    t[x].value = merge(t[x << 1].value, t[x << 1 | 1].value);
}
int main() {
    scanf("%d%d%d", &n, &m, &p);
    k = 100 / p;
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    build(1, 1, n);
    for(int i = 1; i <= m; i++) {
        int opt;
        scanf("%d", &opt);
        if(opt == 1) {
            int l, r, val;
            scanf("%d%d%d", &l, &r, &val);
            modify(1, 1, n, l, r, val);
        }
        else {
            int l, r;
            scanf("%d%d", &l, &r);
            ans.clear();
            query(1, 1, n, l, r);
            printf("%d", ans.size());
            for(auto i : ans) printf(" %d", i.first);
            puts("");
        }
    }
}