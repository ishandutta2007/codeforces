#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000010], type[1000010];
int n;
vector < int > sta1, sta2;
struct node {
    int sum[65];
    int key, opt;
    int l, r;
    node() {
        memset(this, 0, sizeof *this);
    }
};
int sum;
inline void del(node &a) {
    sum -= a.sum[a.key];
}
inline void add(node &a) {
    sum += a.sum[a.key];
}
vector < node > qwq;
inline void calc(node &cur, int opt, int l, int ct) {
    while (qwq.back().r > l) {
        auto &a = qwq.back();
        del(a);
        if (a.l > l) {
            if (a.opt == opt) {
                for (int i = 0; i <= 60; i++) cur.sum[i] += a.sum[i];
            }
            else {
                cur.sum[a.key] += a.r - a.l + 1;
            }
            qwq.pop_back();
        }
        else {
            cur.sum[a.key] += a.r - l;
            a.sum[ct] -= a.r - l;
            a.r = l;
            add(a);
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i), type[i] = __builtin_popcountll(a[i]);
    sta1.push_back(0), sta2.push_back(0);
    long long ans = 0;
    qwq.push_back(node());
    for (int i = 1; i <= n; i++) {
        {
            node cur;
            while (sta1.back() && a[sta1.back()] <= a[i]) {
                int ct = type[sta1.back()];
                sta1.pop_back();
                calc(cur, 0, sta1.back(), ct);
            }
            if (sta1.back() != i - 1) {
                cur.l = sta1.back() + 1, cur.r = i - 1;
                cur.opt = 0, cur.key = type[i];
                qwq.push_back(cur);
                add(cur);
            }
            sta1.push_back(i);
        }
        {
            node cur;
            while (sta2.back() && a[sta2.back()] >= a[i]) {
                int ct = type[sta2.back()];
                sta2.pop_back();
                calc(cur, 1, sta2.back(), ct);
            }
            cur.sum[type[i]]++;
            cur.l = sta2.back() + 1, cur.r = i;
            cur.opt = 1, cur.key = type[i];
            qwq.push_back(cur);
            add(cur);
            sta2.push_back(i);
        }
        ans += sum;
    }
    cout << ans << endl;
}